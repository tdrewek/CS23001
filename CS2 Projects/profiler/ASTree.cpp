//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2022 Kent State University. All rights reserved.
//  Fall 2022
//  srcML 1.0
//
//  Modified by:
//
//

#include "ASTree.hpp"


// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

//  Adds in the includes and profile object declarations
//
void srcML::mainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) {
    tree->mainHeader(profileName, fileName);
}

//  Adds in the includes and declares profile object declarations
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

///  Inserts a profile.count() into each function body.
//
void srcML::functionCount(const std::string& profileName) {
    tree->functionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

    

//
//AST::
//


// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


// Destructor for AST
//
AST::~AST() {
    //Recursively traverse tree and delete from bottom up
    std::list<AST*>::const_iterator i = child.begin();
    while(!child.empty() && i != child.end()) delete *i++;
}


// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;
    for (std::list<AST*>::const_iterator i = actual.child.begin(); i != actual.child.end(); ++i){
        child.push_back(new AST(**i));
    }
}


// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    //Swap all the top level childern (pointers to AST)
    nodes tempNode;
    tempNode = nodeType;
    nodeType = rhs.nodeType;
    rhs.nodeType = tempNode;
    //
    std::string temp;
    temp = text;
    text = rhs.text;
    rhs.text = temp;
    //
    temp = tag;
    tag = rhs.tag;
    rhs.tag = temp;
    //
    temp = closeTag;
    closeTag = rhs.closeTag;
    rhs.closeTag = temp;
    child.swap(rhs.child);
}

/// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::mainHeader(const std::vector<std::string>& profileName,
                     const std::vector<std::string>& fileName     ) {
    //Skip down a couple lines or find main and put it before it
    //Add a node with #include "profile.hpp"
    //For each file profile name, add a node with a profile
    //   declaration "profile foo_cpp("foo.cpp");"
    std::string profStr = "#include \"profile.hpp\"";
    std::list<AST*>::iterator i = child.begin();
    while((*i)->tag != "function")
        i++;
    child.insert(i, new AST(token, profStr));
    std::vector<std::string>::const_iterator profIt = profileName.begin();
    std::vector<std::string>::const_iterator fileIt = fileName.begin();
    while(profIt != profileName.end()) {
        profStr = "\nprofile " + (*profIt) + "(\"" + (*fileIt) + "\")" + ";";
        child.insert(i, new AST(token, profStr));
        profIt++;
        fileIt++;
    }
    child.insert(i, new AST(token, "\n\n"));
}


//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::fileHeader(const std::string& profileName) {
    //Skip down a couple lines or find first function and put it before it
    //Add #include "profile.hpp"
    //Add in the external declaration for that file "extern profile foo_cpp;"
    std::list<AST*>::iterator obj = child.begin();
    while (((*obj)->tag != "function") ) {
        obj++;
    }
    std::string fileCpp = profileName;
    size_t j = 0; 
    while(j != fileCpp.length()){
        if(fileCpp[j] == '_')
            fileCpp[j] = '.';
        ++j;           
    }
    std::string profileString = "#include \"profile.hpp\"";
    profileString = profileString + "\nextern profile " + profileName + ";\n\n"; 
    child.insert(obj, new AST(token, profileString));
}


// Adds in the report to the main file
// Assumes only one return in the main
//
void AST::mainReport(const std::vector<std::string>& profileName) {
    //Find the function with name of "main" in the file
    // -Get the "block" node of this function
    // -Set an iterator to the child.end() of "block"
    // -Decrement it once (to skip the "}")
    // -Search backwards for a "return" tag
    // -Insert the report statements before the return
    std::list<AST*>::iterator it = child.begin();
    while(it != child.end()) {
        //std::cout << "test before if-statement" << std::endl;
        if((*it)->tag == "function") {
            AST* name = (*it)->getChild("name");
            //std::cout << "test between if statements" << std::endl;
            if (((name)->getName() == "main")){
            //std::cout << "test if-statement" << std::endl;
            AST *blockptr = (*it)->getChild("block");
            AST *blockContentPtr = (blockptr)->getChild("block_content");
            AST *returnPtr = blockContentPtr->getChild("return");
            std::list<AST*>::iterator blockIt = returnPtr->child.begin();
            // while((*blockIt)->tag != "return") {
            //     ++blockIt;
            // }
            // --blockIt;
            
            std::string outputCode;
            for(std::vector<std::string>::const_iterator i = profileName.begin(); i !=profileName.end(); ++i) {
                //std::cout << "test for-loop" << std::endl;
                outputCode = outputCode + ("std::cout<< " + (*i) + " <<std::endl; \n");
            }
            AST *output = new AST(token, outputCode);
            //output->text = outputCode;
            returnPtr->child.insert(blockIt,output);
            }
        }
       ++it;
    }
}


// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::functionCount(const std::string& profileName) {
    // for each child in the "unit"
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find <block>, then find <block_content>
    //        Insert the count as first child in <block_content>
    //        Example: main1_cpp.count(__LINE__, "main");
    std::list<AST*>::iterator it = child.begin();
    while(it!=child.end()) {
        if( ((*it)->tag == "function") || ((*it)->tag == "constructor") ||  ((*it)->tag == "destructor")){
            AST *block = (*it)->getChild("block");
            std::string funcName,countCode;
            AST *name = (*it)->getChild("name");
            AST *nameChild = name->child.front();
            funcName = nameChild->text;
            countCode = " " + profileName +".count(__LINE__, \"" + funcName + "\"); \n";
            AST *count = new AST(token);
            count->text = countCode;
            std::list<AST*>::iterator blockIt = block->child.begin();
            while((*blockIt)->text != "{") {
                ++blockIt;
            }
            ++blockIt;
            block->child.insert(blockIt,count);
        }
        ++it;
    }   
}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::lineCount(const std::string& profileName) {
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing

    // I HAVE COMMENTED OUT THE CHUNKS OF CODE THAT I RESTRUCTURED AND SIMPLIFIED
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if((*i)->nodeType == category) {
            if((*i)->tag == "expr_stmt") {
                child.insert(++i, new AST(token, " " + profileName + ".count(__LINE__);"));
                // std::string out = " " + profileName + ".count(__LINE__);";
                // AST* code = new AST(token, out);
                // i++;
                // child.insert(i, code);
                // i--;
            } else if((*i)->tag == "condition"){
                child.insert((*i)->getChild("expr")->child.begin(), new AST(token, profileName + ".count(__LINE__), "));
                // std::string out = " (" + profileName + ".count(__LINE__), ";
                // std::string endParentheses = ")";
                // AST* code = new AST(token, out);
                // AST* code2 = new AST(token, endParentheses);
                // child.insert((*i)->child.begin(), code);
                // if (i == child.end()){
                //     child.pop_back();
                //     child.insert((*i)->child.end(), code2);
                // }
            } else if (!isStopTag((*i)->tag)) {
                (*i)->lineCount(profileName);
            }
        }
    }
}

// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

