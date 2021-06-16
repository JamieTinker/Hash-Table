//Jamie Tinker 
//
//hash.h

#ifndef HASH_H_
#define HASH_H_

template <class V, class K>
class hashMap {
public:
	hashMap();
	int hasher(K key);
	bool empty();
	int size();	
	V operator[](K key); 
	void changeValue(K key, V value); 
	bool find(V value);	
	int count(int index);	
	void insert(K key, V value);
	void remove(K key);
	void printTable();

private:
	int tableSize = 10;
	
	template <class V, class K>
	struct item {
		K key;
		V value;
		item<V, K>* next;
	};
	
	std::vector< item<V, K>*  > hashTable;
};

#include "hash.cpp" //including cpp file because of template use 

#endif // !HASH_H_
