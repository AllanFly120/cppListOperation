// Name:
// Loginid:
// CSCI 455 PA5
// Fall 2015

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
  data = new ListType[HASH_SIZE]();
  hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
  data = new ListType[hSize]();
  hashSize = hSize;
}


int * Table::lookup(const string &key) {
  int* tmp = lookUp(data[hashCode(key)],key);

  return tmp;
}

bool Table::remove(const string &key) {
  int tmp = removeNode(data[hashCode(key)], key);
  if (tmp == -1) {
    return false;
  }else {
    return true;
  }
}

bool Table::insert(const string &key, int value) {
  if (lookUp(data[hashCode(key)],key)!=NULL) {
//    cout << "The student is already in the table. "<<endl;
    return false;
  }else{
    addNode(data[hashCode(key)], key, value);
    return true;
  }
}

int Table::numEntries() const {
  int rtn = 0;
  int i;
  for(i = 0;i<hashSize;i++) {
    rtn += getLength(data[i]);
  }
  return rtn;     
}


void Table::printAll() const {
  int i;
  for(i = 0;i<hashSize;i++){
    printList(data[i]);
  }
}

void Table::hashStats(ostream &out) const {
  out << "number of buckets: " << hashSize << endl;
  out << "number of entries: " << Table::numEntries() << endl;
  int numBuck = 0;
  int longestChain = 0;
  int i;
  int length;
  for(i = 0;i<hashSize;i++) {
    length = getLength(data[i]);
    if(length>0) {
      numBuck++;
      if(length > longestChain) longestChain = length;
    }
  }
  out << "number of non-empty buckets: " << numBuck << endl;
  out << "longest chain: " << longestChain << endl;
}


// add definitions for your private methods here
