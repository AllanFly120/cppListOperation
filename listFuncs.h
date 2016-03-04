// Name:
// Loginid:
// CSCI 455 PA5
// Fall 2015


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.
void initList(ListType &list);
//remove a node in a list
//if the theKey exists in the list, delete the node and return its value
//if the list doesn't contain the key, do nothing and return -1
int removeNode(ListType &list, const string &theKey);

//determine whether the linkedlist contains the key
//return 0: the list doesnt contain the key
//return 1: the list contains the key
int* lookUp(ListType &list, const string &theKey);

//add a node in a list
//if the theKey exists in the list,  remove the existing one and add the newer value
//return -1: if the list doesn't contain the key, add the node at the end of list;
int addNode(ListType &list, const string &theKey, const int theVal);




void printList(ListType list);

int getLength(ListType list);















// keep the following line at the end of the file
#endif
