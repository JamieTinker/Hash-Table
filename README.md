# Hash-Table

Hash Table implementation using C++ and Visual Studio 2019

This simple hash table uses a template and can store key, value pairs. The table is set up using a vector of item pointers ( vector< item<V, K>* ), which link upon collisions. This table only
uses 10 vector indicies to store items (0 - 9). Keys must be strings, but values can be any data type. 

This table can perform insertion, deletion, searching by key, accessing value by key using [ ] operator, and can change value of existing item. 
