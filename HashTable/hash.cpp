//Jamie Tinker
//
//hash.cpp

#include <iostream>
#include <vector>
#include <string>
#include "hash.h"

using namespace std;

#ifndef _HASH_CPP_
#define _HASH_CPP_

//constructor - testing with key of strings and value of integers
template <class V, class K>
hashMap<V, K>::hashMap() {
	for (int i = 0; i < tableSize; i++) {		//initialize table buckets 
		item<V, K>* p = new item<V, K>;
		hashTable.push_back(p);			
		hashTable[i]->key = "empty";
		hashTable[i]->value = 0;
		hashTable[i]->next = nullptr;	 //ptr for chaining collisions
	}
}


//hash function
template <class V, class K>
int hashMap<V, K>::hasher(K key) {
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash += (int)key[i];
	}
	index = abs(hash) % tableSize; //tablesize = 10, index = 0 through 9

	return index;
}


//returns true if hashmap is empty
template <class V, class K>
bool hashMap<V, K>::empty() {	
	bool isEmpty = 1;
	for (int i = 0; i < tableSize; i++) {
		if (hashTable[i]->key != "empty") {
			isEmpty = 0;
		}
	}
	return isEmpty;
}


//returns num of items in hashmap
template <class V, class K>
int hashMap<V, K>::size() {	//HW
	int size = 0;
	for (int i = 0; i < tableSize; i++) {
		size = size + count(i);
	}
	return size;
}


//gets value associated with key perameter
template <class V, class K>
V hashMap<V, K>::operator[](K key) {	 
	int index = hasher(key);
	int number = count(index);
	bool foundKey = false;
	V val = 0;

	item<V, K>* ptr = hashTable[index];

	while (ptr != nullptr) {
		if (ptr->key == key) {
			val = ptr->value;
			foundKey = true;
		}
		ptr = ptr->next;
	}
	if (foundKey == true) {
		cout << "The value associated with the key " << key << " is " << val << endl << endl;
		return val;
	}
	else {
		cout << "The key " << key << " does not exist in the hash table. " << endl << endl;
		return val;
	}
}


//changes the existing value associated with the key parameter to the new value parameter
template <class V, class K>
void hashMap<V, K>::changeValue(K key, V value) {	
	int index = hasher(key);
	int number = count(index);
	bool foundKey = false;

	item<V, K>* ptr = hashTable[index];

	while (ptr != nullptr) {
		if (ptr->key == key) {
			ptr->value = value;
			foundKey = true;
		}
		ptr = ptr->next;
	}
	if (foundKey == true) {
		cout << "The value associated with the key " << key << " has been changed to " << value << endl << endl;
	}
	else {
		cout << "The key " << key << " does not exist in the hash table. " << endl << endl;
	}
}


//search for item by in hashmap by value
template <class V, class K>
bool hashMap<V, K>::find(V value) {		//HW
	bool found = 0;
	
	for (int i = 0; i < tableSize; i++) {
		int number = count(i);
		item<V, K>* ptr = hashTable[i];
		
		if (number != 0) {
			if (ptr->value == value) {
				found = 1;
			}
			
			while (ptr->next != nullptr) {
				if (ptr->next->value == value) {
					found = 1;
				}
				ptr = ptr->next;
			}
		}
	}
	return found;
}


//sum number of items in bucket at given index
template <class V, class K>
int hashMap<V, K>::count(int index) {	
	int count = 0;
	if (hashTable[index]->key == "empty") {
		return count;
	}
	else {
		count++;
		
		item<V, K>* ptr = hashTable[index];
		
		while (ptr->next != nullptr) {
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}


//insert a new item into the hashmap
template <class V, class K>
void hashMap<V, K>::insert(K key, V value) {
	int index = hasher(key);
	
	if (hashTable[index]->key == "empty") {
		hashTable[index]->key = key;
		hashTable[index]->value = value;
	}
	else {
		item<V, K>* ptr = hashTable[index];
		item<V, K>* n = new item<V, K>;
		n->key = key;
		n->value = value;
		n->next = nullptr;
	
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}


//find and remove an item from the hashmap by key
template <class V, class K>
void hashMap<V, K>::remove(K key) {
	int index = hasher(key);
	int number = count(index);
	item<V, K>* ptr = hashTable[index];
	item<V, K>* delptr;
	item<V, K>* ptr1;
	item<V, K>* ptr2;

	//case 1 - the index is empty 
	if (number == 0) {
		cout << "The key " << key << " does not exist in the hash table" << endl << endl;
	}

	//case 2 - only one item at the index 
	else if (number == 1 && ptr->key == key) {
		ptr->key = "empty";
		ptr->value = 0;
		ptr->next = nullptr;
		cout << "The item with key " << key << " has been deleted from the bucket at index " << index << ", and that bucket is now empty" << endl << endl;
	}

	//case 3 - there is more than one item at the index but the item we want to delete is the first one in list
	else if (number > 1 && ptr->key == key) {
		delptr = hashTable[index];
		hashTable[index] = hashTable[index]->next;
		delete delptr;
		cout << "The item with key " << key << " has been deleted from the hash table at index " << index << endl << endl;
	}
	
	//case 4 - there is more than one item at the index but the item we want to delete not in the first position of list
	else {
		ptr1 = hashTable[index]->next;
		ptr2 = hashTable[index];

		while (ptr1 != nullptr && ptr1->key != key) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		if (ptr1 == nullptr) {	//the key was not found
			cout << "The key " << key << " does not exist in the hash table" << endl << endl;
		}
		else { //found key 
			delptr = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;

			delete delptr;
			cout << "The item with key " << key << " has been deleted from the hash table at index " << index << endl << endl;
		}
	}
}


//print contents of hash table for testing
template <class V, class K>
void hashMap<V, K>::printTable() {
	int number;
	for (int i = 0; i < tableSize; i++) {
		number = count(i);
		
		if(number < 2){
			cout << "-------------" << endl;
			cout << "index = " << i << endl;
			cout << "This bucket contains " << number << " items." << endl << endl;
			cout << "key: " << hashTable[i]->key << endl;
			cout << "value: " << hashTable[i]->value << endl << endl;	
		}
		else {
			cout << "-------------" << endl;
			cout << "index = " << i << endl;
			cout << "This bucket contains " << number << " items." << endl << endl;

			item<V, K>* ptr = hashTable[i];
			while (ptr != nullptr) {				
				cout << "key: " << ptr->key << endl;
				cout << "value: " << ptr->value << endl << endl; 
				ptr = ptr->next;
			}
		}
	}
}

#endif // !_HASH_CPP_