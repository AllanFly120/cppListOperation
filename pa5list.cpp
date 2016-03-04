// pa5list.cpp
// A program to test the linked list code necessary for a hash table chain.

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
  ListType list;
  
  initList(list);
  
  cout << "an empty list: ";
  printList(list);
  
  addNode(list, "Allan", 32);
  addNode(list, "Joe", 50);
  addNode(list, "Mike", 25);
  cout << "a list: ";
  printList(list);
  
  Node *list2 = NULL;
  addNode(list2, "Sue", 12);
  addNode(list2, "Max", 17);
  
  cout << "another list: ";
  printList(list2);
  
  lookUp(list, "Allan");
  cout << *lookUp(list, "Allan")<<endl;
  
  removeNode(list, "Allan");
  cout << "after remove front from first list: ";
  printList(list);
  removeNode(list, "May");
  cout << "after remove front from first list: ";
  printList(list);
  removeNode(list, "Mike");
  cout << "after remove front from first list: ";
  printList(list);
  removeNode(list, "Joe");
  cout << "after remove front from first list: ";
  printList(list);
  
  removeNode(list2, "Max");
  cout << "after remove front from first list: ";
  printList(list2);
  cout << "after remove last from second list: ";
  printList(list2);
  
  removeNode(list2, "Sue");
  cout << "after remove last from second list: ";
  printList(list2);
  
  
  return 0;
}
