#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "NodeT.h"

using namespace std;


template <class T>
class LinkedList{
public:
  // Default constructor
  LinkedList();

  // Paratmerterized constructor
  LinkedList(int length, T* values);

  // copy constructor
  LinkedList(const LinkedList<T> &);

  // asignment operator
  LinkedList<T> & operator = (const LinkedList<T> &);

  // default destructor
  ~LinkedList();

  // size fot the LinkedList
  int size() const;

  // get the n-th item in the LinkedList
  T& getItem(int n) const;

  // insert element X into the LinkedList at position pos
  void insert(T x,int pos);

  // remove the n-th item in the LinkedList
  void remove (int n);

private:
  // size
  int Size;

  // root
  NodeT<T>* root;

  // release memory
  void cleanup();
};

// default constructor
template <class T>
LinkedList<T>::LinkedList(){

  // an empty LinkedList
  Size = 0;
  root = NULL;
}

// parameterized constructor
template <class T>
LinkedList<T>::LinkedList(int length, T* values){
  Size = length;
  root = new NodeT<T>;
  root->value = values[0];

  NodeT<T>* curr = root;

  // traverse the given array values and copy each of them to the LinkedList
  for (int i = 1;i < length;i++){
    NodeT<T>* newT = new NodeT<T>;
    newT->value = values[i];
    curr->next = newT;
    curr = newT;
  }
  curr->next = NULL;
}

// copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & toCopy){
    Size = toCopy.size();
    root = new NodeT<T>;
    NodeT<T>* curr = root;
    NodeT<T>* newT;

    // copy each element in the LinkedList toCopy
    for (int i = 0;i < Size;i++){
        curr->value = toCopy.getItem(i);

	// create the next element
	if (i + 1 == Size)
          newT = NULL;
	else
	  newT = new NodeT<T>;
	
	curr->next = newT;
	curr = newT;
    }
  
}

// asignment operator
template <class T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & toAssign){

  // selfAssignment-check
  if (this != &toAssign){

    // release memory
    cleanup();
    
    Size = toAssign.size();
    root = new NodeT<T>;
    NodeT<T>* curr;
    NodeT<T>* newT;
    curr = root;

    // same as copy constructor
    for (int i = 0;i < Size;i++){
        curr->value = toAssign.getItem(i);
	
	if (i + 1 == Size)
          newT = NULL;
	else
	  newT = new NodeT<T>;
	
	curr->next = newT;
	curr = newT;
    }
    
  }
  return *this;
}

// default destructor
template <class T>
LinkedList<T>::~LinkedList(){
  cleanup();
}

// size fot the LinkedList
template <class T>
int LinkedList<T>::size() const{
  return Size;
}

// get the n-th item in the LinkedList
template <class T>
T& LinkedList<T>::getItem(int n) const{
  
  int count = 0;
  NodeT<T>* curr = root;

  // traverse in the LinkedList until the n-th item
  while (count != n){
    if (curr->next == NULL)
      break;
    
    curr = curr->next;
    count++;
  }

  return curr->value;
}

// insert element X into the LinkedList at position pos
template <class T>
void LinkedList<T>::insert(T x,int pos){
  NodeT<T>* newNode = new NodeT<T>;
  newNode->value = x;
  
  // if pos = 0, insert X as the root
  if (pos == 0){
    newNode->next = root;
    root = newNode;
    Size++;
    return;
  }
  
  // traverse in the LinkedList until pos-th element
  NodeT<T>* curr;
  NodeT<T>* prev;
  curr = root;
  
  int count = 0;
  while (count != pos){
    prev = curr;
    curr = curr->next;
    count++;
  }

  prev->next = newNode;
  newNode->next = curr;
  Size++;
  
  return;
}

// remove the n-th item in the LinkedList
template <class T>
void LinkedList<T>::remove (int n){

  if (root == NULL)
    return;
  
  // if n = 0, remove root
  if (n == 0){
    NodeT<T>* todelete = root;
    root = root->next;
    delete todelete;
    Size--;
    return;
  }

  // traverse in the LinkedList until n-th element
  NodeT<T>* curr = root;
  NodeT<T>* prev;
  int count = 0;
  while (count != n){
    prev = curr;
    
    if (curr->next == NULL)
      break;
    
    curr = curr->next;
    count++;
  }
  
  prev->next = curr->next;
  delete curr;
  Size--;
  return;
}

template <class T>
void LinkedList<T>::cleanup(){
  if (root == NULL)
    return;

  // traverse in the LinkedList and delete every element
  NodeT<T>* curr = root;
  while (curr != NULL){
    NodeT<T>* todelete = curr;
    curr = curr->next;
    delete todelete;
  }
  Size = 0;
  root = NULL;
  return;
}
#endif
