// implementing hashtable
// using chaning linked list
#pragma once

#include <iostream>
#include <string>
using namespace std;


template<typename T>
class node{
public:
    T data;
    string key;
    node* next;

    node(string s, T d){
        data = d;
        key = s;
        next = nullptr;
    }

    // recursive detructor call
    ~node(){
        if(next != nullptr)
            delete next;
    }
};


template<typename T>
class hashTable{

    node<T>** table;
    int table_size;
    int curr_size;

    int hashFn(string key){
        int idx = 0;
        int p = 1;
        for(int j = 0; j < key.length(); j++){
            // % table_size is to
            idx = idx + (key[j]*p) % table_size;
            idx = idx % table_size;
            p = (p*27) % table_size;
        }
        return idx;
    }

public:
    hashTable(int ts = 7){
        table_size = ts;
        curr_size = 0;
        table = new node<T>*[table_size];

        // set value of every bucket to null
        for(int i = 0; i < table_size; i++){
            table[i] = nullptr;
        }
    }

    void insert(string key, T val){
        // allot the index for key using hashFn
        int idx = hashFn(key);

        // create a node to put in idx in table
        node<T>* n = new node<T>(key, val);

        // add the node at the head of linked list
        n->next = table[idx];
        table[idx] = n;

        // increase the current size
        curr_size++;
    }

    void print(){
        for(int i = 0; i < table_size; i++){
            cout << "Bucket " << i << ": ";
            node<T>* temp = table[i];

            while(temp != nullptr){
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T* search(string key){
        int idx = hashFn(key);
        node<T>* temp = table[idx];

        while(temp != nullptr){
            if(temp->key == key)
                return &temp->data;
            temp = temp->next;
        }

        // return nullptr if key not present
        return nullptr;
    }

    T& operator[](string key){
        T* f = search(key);
        if(f == nullptr){
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }
};
