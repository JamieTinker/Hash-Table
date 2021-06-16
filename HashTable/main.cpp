//Jamie Tinker
//
//main.cpp

#include <iostream>
#include <vector>
#include <string>
#include "hash.h"

using namespace std;

int main() {
	hashMap<int, string> hashObject;

	cout << "Welcome to the Hash Table demonstration:" << endl << endl;
	cout << "is the hash table empty? " << hashObject.empty() << endl << endl;
	cout << "The number of items in the hash table is: " << hashObject.size() << endl << endl;
	
	cout << "---------------------------------------" << endl << endl;
	cout << "The empty hash table looks like this: " << endl;
	hashObject.printTable();

	cout << endl << endl << "---------------------------------------------" << endl << endl;
	cout << "We will now insert 11 items into the hash table.." << endl << endl;

	hashObject.insert("paul", 14);
	hashObject.insert("doug", 47);
	hashObject.insert("james", 88);
	hashObject.insert("rick", 32);
	hashObject.insert("chris", 17);
	hashObject.insert("jane", 6);
	hashObject.insert("hannah", 1);
	hashObject.insert("jamie", 5);
	hashObject.insert("patrick", 44);
	hashObject.insert("robert", 191);
	hashObject.insert("sam", 22);

	cout << "Is the table still empty? " << hashObject.empty() << endl << endl;
	cout << "The number of items in the hash table is: " << hashObject.size() << endl << endl;
	cout << "The hash table now looks like this: " << endl << endl;

	hashObject.printTable();

	cout << "-----------------------------------------" << endl << endl;
	cout << "We will use the find(V value) function to see if values exist within the hash table.." << endl << endl;
	cout << "Does the number 191 exist somewhere in the table? " << hashObject.find(191) << endl << endl;
	cout << "Does the number 5 exist somewhere in the table? " << hashObject.find(5) << endl << endl;
	cout << "Does the number 88 exist somewhere in the table? " << hashObject.find(88) << endl << endl;
	cout << "Does the number 465 exist somewhere in the table? " << hashObject.find(465) << endl << endl;

	cout << "-----------------------------------------" << endl << endl;
	cout << "We will now use the operator[](K key) function to get a key's value.." << endl << endl;

	hashObject["chris"];

	cout << "Now We will attempt to get a value from a key that doesn't exist in the hash table.." << endl << endl;

	hashObject["harry"];

	cout << "-----------------------------------------" << endl << endl;
	cout << "We will now use the changeValue(K key, V value) function to change a key's value.." << endl << endl;

	hashObject.changeValue("chris", 37);

	cout << "Now We will attempt to get a value from a key that doesn't exist in the hash table.." << endl << endl;

	hashObject.changeValue("harry", 55);

	cout << "-----------------------------------------" << endl << endl;
	cout << "The number of items in the hash table is: " << hashObject.size() << endl << endl;
	cout << "We will now delete the following items from the hash table: \npatrick, doug, robert, and jamie.. " << endl << endl;

	hashObject.remove("patrick");
	hashObject.remove("doug");
	hashObject.remove("robert");
	hashObject.remove("jamie");

	cout << "The number of items in the hash table is now: " << hashObject.size() << endl << endl;
	cout << "The hash table now looks like this:" << endl;
	hashObject.printTable();

	cout << "----------------------------------------" << endl << endl;
	cout << "End of demo.." << endl << endl;

	cin.get(); //wait for enter to be pressed
}