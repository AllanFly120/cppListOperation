// Name:
// Loginid:
// CSCI 455 PA5
// Fall 2015


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}




//*************************************************************************
// put the function definitions for your list functions below
int removeNode(ListType &list, const string &theKey){
  if(list==NULL)return -1;
  
  if (list->next==NULL) {        //only one element
    if (list->key==theKey) {
      int tmpVal = list->value;
      delete list;
      list = NULL;
      return tmpVal;
    }else {
      return -1;
    }
  }
  Node *p = list;
  if (p->key==theKey) {
    Node* tmp = p;
    int tmpVal = tmp->value;
    list = list->next;
    delete tmp;
    return tmpVal;
  }
  while (p->next->next!=NULL) {
    if(p->next->key == theKey) break;
    p = p->next;
  }
  if (p->next->key==theKey) {
    Node* tmp = p->next;
    int tmpVal = tmp->value;
    if (p->next->next==NULL) {     //if the last element is the one needs to be removed
      p->next = NULL;
    }else{
      p->next = p->next->next;
    }
    delete tmp;
    return tmpVal;
  }
  return -1;
}

int* lookUp(ListType &list, const string &theKey){
  if(list==NULL)return NULL;
  Node *p = list;
  int *rtn;
  while (p!=NULL) {
    if (p->key==theKey) {
      rtn = &(p->value);
      return rtn;
    }
    p = p->next;
  }
  return NULL;
}

int addNode(ListType &list, const string &theKey, const int theVal){
  Node* newNode = new Node(theKey, theVal);
  int rtn = removeNode(list, theKey);  //no matter whether the node exists, we remove it.
  newNode->next = list;                 //then add the new node in the front of the list;
  list = newNode;
  return rtn;
}

void printList(ListType list){
  if (list == NULL) {
//    cout << "<empty>"<<endl;
    return;
  }
  
  Node *p = list;
  while (p != NULL) {
    cout << p->key << " "<< p->value << endl;
    p = p->next;
  }
}

int getLength(ListType list){
  if(list==NULL)return 0;
  int rtn = 0;
  Node *p = list;
  while (p!=NULL) {
    rtn++;
    p = p->next;
  }
  return rtn;
}

void initList(ListType &list) {
  list = NULL;
}
