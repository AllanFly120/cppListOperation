// Name:
// Loginid:
// CSCI 455 PA5
// Fall 2015

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" 
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*
  string input;
  while (true) {
    cout<<"cmd>";
    cin>>input;
//    getline(cin, input);
    if (input=="quit") {
      return 0;
    }
    else if(input=="help"){
      cout<<"insert name score: Insert this name and score in the grade table."<<endl;
      cout<<"change name score: Change the score for name"<<endl;
      cout<<"lookup name: Lookup the name, and print out his or her score."<<endl;
      cout<<"remove name: Remove this student."<<endl;
      cout<<"print: Prints out all names and scores in the table."<<endl;
      cout<<"size: Prints out the number of entries in the table."<<endl;
      cout<<"stats: Prints out statistics about the hash table at this point. "<<endl;
      cout<<"help: Prints out a brief command summary."<<endl;
      cout<<"quit: Exits the program."<<endl;
    }
    else if(input=="stats"){
      grades->hashStats(cout);
    }
    else if(input=="print"){
      grades->printAll();
    }
    else if(input=="insert"){
      string key;
      cin>>key;
      string strScore;
      cin>>strScore;
      int tmp = grades->insert(key, atoi(strScore.c_str()));
      if (tmp == true) {
        cout<<"Inserted. "<<endl;
      } else {
        cout<<"The student is already in the table. "<<endl;
      }
      cout<<endl;
      
    }
    else if(input=="change"){
      string key;
      cin>>key;
      string strScore;
      cin>>strScore;
      int* tmp  =  grades->lookup(key);
      if (tmp == NULL) {
        cout<<"No such a student. "<<endl;
      } else {
 //       grades->insert(key, atoi(strScore.c_str()));
 				*tmp = atoi(strScore.c_str());
        cout<<"Changed. "<<endl;
      }
      
    }
    else if (input=="lookup"){
      string key;
      cin>>key;
      int *score = grades->lookup(key);
      if (score==NULL) {
        cout<<"No such a student. "<<endl;
      } else {
        cout<<*score<<endl;
      }
    }
    else if (input=="remove"){
      string key;
      cin>>key;
      int tmp = grades->remove(key);
      if (tmp==0) {
        cout<<"No such a student. "<<endl;
      } else {
        cout<<key<<"is deleted. "<<endl;
      }
    }
    else if (input=="size"){
      cout<<grades->numEntries()<<endl;
    }
    else{
      cout<<"ERROR: invalid command "<<endl;
    }
    
  }


  return 0;
}
