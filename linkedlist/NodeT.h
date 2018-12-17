#ifndef NODET_H
#define NODET_H
using namespace std;

// define node type in the LinkedList
template <class T>
struct NodeT{
   T value;
   NodeT<T>* next;
};

#endif
