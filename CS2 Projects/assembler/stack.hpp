#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer: 
// Date:       Fall 2022
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>

////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class Node{
public:
	Node() : next(0) {}; // default constructor
    Node(const T& item) : data(item), next(0) {};
    T data;
    Node<T>* next;
private:
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV: tos -> x1 -> x2 -> x3 -> x4 -> x5 -> xN -> 0
//
//    
template <typename T>
class stack {
public:
              stack     () : tos(0) {}; 		// default constructor
              stack     (const stack<T>&); 		// copy constructor
              ~stack    (); 					// destructor
    void      swap      (stack<T>&); 	        // constant time swap
    stack<T>& operator= (stack<T>);
	bool      empty     () const;
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};

// destructor
template <typename T>
stack<T>::~stack() {
    Node<T> *temp;
    while(tos != 0){
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

// copy constructor
template <typename T>
stack<T>::stack(const stack<T>& actual) {
    Node<T> *temp = actual.tos, *bottom = 0;
    tos = 0;
    while (temp != 0){
    if (tos == 0){
        tos = new Node<T>(temp->data);
        bottom = tos;
    } else {
        bottom->next = new Node<T>(temp->data);
        bottom = bottom->next;
    }
    temp = temp->next;
    }
}

// constant time swap
template <typename T>
void stack<T>::swap(stack<T>& rhs){
    Node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

// overloading assignment
template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs){
    swap(rhs);
    return *this;
}

template <typename T>
bool stack<T>::empty() const{
    return tos == 0;
}

template <typename T>
bool stack<T>::full() const{
    Node<T> *temp = new(std::nothrow) Node<T>();
    if (temp == 0) return true;
    delete temp;
    return false;
}

// REQUIRES: tos -> x1 -> x2 -> ... xN -> 0
// ENSURES: tos -> item -> x1 -> x2 -> ... xN -> 0
template <typename T>
void stack<T>::push(const T& item){
    assert(!full());
    Node<T> *temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
}

// REQUIRES: tos != 0 || tos -> x1 -> x2 -> ... xN -> 0
// ENSURES: tos -> x2 -> ... xN -> 0
template <typename T>
T stack<T>::pop(){
    assert(!empty());
    Node<T> *temp = tos;
    T result = tos->data;
    tos = tos->next;
    delete temp;
    return result;
}

template <typename T>
T stack<T>::top() const{
	assert(!empty());
	return tos->data;
}


#endif

