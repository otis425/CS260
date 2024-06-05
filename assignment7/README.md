![Static Badge](https://img.shields.io/badge/Version-1.0-white)
## Assignment Requirements
### Design:
 - Create a design illustrating how data can be stored in a hash table and the problems it can solve.

### Testing:
 - Develop tests (minimum one per functionality) to validate the hashtable's functionality before coding.

### Simple Hashtable:
- Implement a basic hashtable resolving collisions by overwriting old values with new ones.
- Describe the hashing method used.
- Implement insert and contains functions.
### Smarter Hashtable:
- Implement a smarter hashtable using double hashing or chaining.
- Include the same functions as the simple hashtable.
###Collision Comparison:
- Analyze collision frequency and its impact on complexity for insert and contains methods.

## Meeting Requirements
### Design : 
![image](https://github.com/otis425/CS260/assets/71042122/92a6f57c-6ba6-412c-8702-939426e0a523)

### Testing:
``` c++
#include <iostream>
#include <cassert>
#include "stringhashtable.h"

int main() {
    // Create a hashtable
    simple_string_hash string_hashtable;
    // Test insert
    std::cout << " INSERT" << std::endl;
    std::cout << "  add John - 143" << std::endl;
    string_hashtable.insert("John", 143);
    string_hashtable.print_tree();
    std::cout << "  add Diane - 23" << std::endl;
    string_hashtable.insert("Diane", 23);
    string_hashtable.print_tree();
    std::cout << "  add Alice - 42" << std::endl;
    string_hashtable.insert("Alice", 42);
    string_hashtable.print_tree();
    std::cout << "  add Bob - 99" << std::endl;
    string_hashtable.insert("Bob", 99);
    string_hashtable.print_tree();
    std::cout << std::endl; 

    // Test get
    std::cout << " GET" << std::endl;
    std::cout << "get John: " << string_hashtable.get("John") << std::endl;
    std::cout << "get Diane: " << string_hashtable.get("Diane") << std::endl;
    std::cout << "get Alice: " << string_hashtable.get("Alice") << std::endl;
    std::cout << "get Bob: " << string_hashtable.get("Bob") << std::endl;
    std::cout << std::endl;

    // Test collision
    std::cout << " COLLISION" << std::endl;
    std::cout << "  add Jill - 100" << std::endl;
    string_hashtable.insert("Jill", 100);
    string_hashtable.print_tree();
    assert(string_hashtable.get("Jill") == 100);
    std::cout << "  add Alyssa - 10" << std::endl;
    string_hashtable.insert("Alyssa", 10);
    string_hashtable.print_tree();
    assert(string_hashtable.get("Alyssa") == 10);
    std::cout << std::endl;

    // Test delete
    std::cout << " DELETE" << std::endl;
    std::cout << "  remove Diane" << std::endl;
    string_hashtable.remove("Diane");
    string_hashtable.print_tree();
    std::cout << "  remove Bob" << std::endl;
    string_hashtable.remove("Bob");
    string_hashtable.print_tree();
    std::cout << "  remove Alyssa" << std::endl;
    string_hashtable.remove("Alyssa");
    string_hashtable.print_tree();
    assert(string_hashtable.get("Diane") == 0); // After deletion, the value should be 0
    assert(string_hashtable.get("Bob") == 0); // After deletion, the value should be 0
    assert(string_hashtable.get("Alyssa") == 0); // After deletion, the value should be 0

    std::cout << "====================" << std::endl;
    std::cout << "SMART STRING HASH" << std::endl;

    // Create a hashtable
    smart_stringhash smart_hashtable;
    // Test insert
    std::cout << " INSERT" << std::endl;
    std::cout << "  add John - 143" << std::endl;
    smart_hashtable.insert("John", 143);
    smart_hashtable.print_tree();
    std::cout << "  add Diane - 23" << std::endl;
    smart_hashtable.insert("Diane", 23);
    smart_hashtable.print_tree();
    std::cout << "  add Alice - 42" << std::endl;
    smart_hashtable.insert("Alice", 42);
    smart_hashtable.print_tree();
    std::cout << "  add Bob - 99" << std::endl;
    smart_hashtable.insert("Bob", 99);
    smart_hashtable.print_tree();
    std::cout << std::endl; 

    // Test get
    std::cout << " GET" << std::endl;
    std::cout << "get John: " << smart_hashtable.get("John") << std::endl;
    std::cout << "get Diane: " << smart_hashtable.get("Diane") << std::endl;
    std::cout << "get Alice: " << smart_hashtable.get("Alice") << std::endl;
    std::cout << "get Bob: " << smart_hashtable.get("Bob") << std::endl;
    std::cout << std::endl;

    // Test collision
    std::cout << " COLLISION" << std::endl;
    std::cout << "  add Jill - 100" << std::endl;
    smart_hashtable.insert("Jill", 100);
    smart_hashtable.print_tree();
    assert(smart_hashtable.get("Jill") == 100);
    std::cout << "  add Alyssa - 10" << std::endl;
    smart_hashtable.insert("Alyssa", 10);
    smart_hashtable.print_tree();
    assert(smart_hashtable.get("Alyssa") == 10);
    std::cout << std::endl;

    // Test delete
    std::cout << " DELETE" << std::endl;
    std::cout << "  remove Diane" << std::endl;
    smart_hashtable.remove("Diane");
    smart_hashtable.print_tree();
    std::cout << "  remove Bob" << std::endl;
    smart_hashtable.remove("Bob");
    smart_hashtable.print_tree();
    std::cout << "  remove Alice" << std::endl;
    smart_hashtable.remove("Alice");
    smart_hashtable.print_tree();
    assert(smart_hashtable.get("Diane") == 0); // After deletion, the value should be 0
    assert(smart_hashtable.get("Bob") == 0); // After deletion, the value should be 0
    assert(smart_hashtable.get("Alice") == 0); // After deletion, the value should be 0
    
}
```
## Simple Hashtable:
### Functions :
#### ADD :
code
```c++
void insert(std::string key, int value) {
        // create person with key-value
        person *identity = new person;
        identity->keyname = key;
        identity->amount = value;
        // place in hashtable
        int hash_index = hash(key);
        if (hashtable[hash_index] == nullptr) { // if nothing
            hashtable[hash_index] = identity;
        } else {
            delete hashtable[hash_index]; // delete the old value
            hashtable[hash_index] = identity; // replace 
        }
    }
```
input

![image](https://github.com/otis425/CS260/assets/71042122/6f23e02d-7b9a-4d92-ad9d-cbd7da465763)

output

![image](https://github.com/otis425/CS260/assets/71042122/43502f88-190a-46fc-983b-4508d8c48957)

#### GET :
code
```c++
int get(std::string key) {
        // return value for key
        int index = hash(key);
        if (hashtable[index] == nullptr || hashtable[index]->keyname != key) {
            return 0;
        } else {
            int returnamount = hashtable[index]->amount;
            return returnamount;
        }
        
    }
```
input

![image](https://github.com/otis425/CS260/assets/71042122/6e60dcd4-1d74-4132-8954-04edc5238c8c)

output

![image](https://github.com/otis425/CS260/assets/71042122/7be6262b-3da3-492e-8145-f30dc8106a71)

#### COLLISION :
code in insert function
``` c++
if (hashtable[hash_index] == nullptr) { // if nothing
            hashtable[hash_index] = identity;
        } else {
            delete hashtable[hash_index]; // delete the old value
            hashtable[hash_index] = identity; // replace 
        }
```
input

![image](https://github.com/otis425/CS260/assets/71042122/3280c1e5-1f4e-4061-89ec-9b2c2b230ffe)

output

![image](https://github.com/otis425/CS260/assets/71042122/0b058021-680d-4634-bc45-065b395aaa5c)

#### REMOVE :
code
``` c++
 void remove(std::string key) {
        // Remove the key-value pair from the hashtable
        int index = hash(key);
        if (hashtable[index]->keyname != key) {
            return;
        }
        delete hashtable[index];
        hashtable[index] = nullptr; // Set the pointer to nullptr after deletion
    }

```
input

![image](https://github.com/otis425/CS260/assets/71042122/ed9f49fc-3626-406b-b076-17d308693a87)

output

![image](https://github.com/otis425/CS260/assets/71042122/2d47dfd3-ecde-48a1-b0ef-268ab8f8ab17)

### Hashing
```c++
 int hash(std::string key){
        int firstLetter = std::toupper(key[0]) - 'A';
        return firstLetter;
    }
```
My Hash function simply takes in a string, and returns the ascii number of the first letter. I subtract A to slide all the letters so that A is 0 and Z is 25.

### Smarter Hashtable:
#### ADD :
code
```c++
void insert(std::string key, int value) {
        // create person with key-value
        person *identity = new person;
        identity->keyname = key;
        identity->amount = value;
        // place in hashtable
        int hash_index = hash(key);
        if (hashtable[hash_index] == nullptr) { // if nothing
            hashtable[hash_index] = identity;
        } else {
            person* current = hashtable[hash_index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = identity;
        }
    }
```
input

![image](https://github.com/otis425/CS260/assets/71042122/08131d5a-ddd1-48de-9a71-eca137d03d80)

output

![image](https://github.com/otis425/CS260/assets/71042122/7b391d22-d8de-41ad-93c5-d22152200f44)


#### GET :
code
```c++
int get(std::string key) {
        // return value for key
        int index = hash(key);
        if (hashtable[index] == nullptr) {
            return 0;
        } else {
            if (hashtable[index]->keyname != key){ // if index is occupied but different key
                person* current = hashtable[index];
                while (current->next != nullptr) { // iterate through the linked list
                    if (current->keyname == key) { // if key is found
                        return current->amount;
                    }
                    current = current->next; 
                }
                if (current->keyname != key) { // if key is not found
                    return 0;
                } else {
                    return current->amount;
                }
                
            } else {
                return hashtable[index]->amount;
            }
        }
    }
```
input

![image](https://github.com/otis425/CS260/assets/71042122/938d9e3d-f90c-4844-a720-25994c5d0ba7)

output

![image](https://github.com/otis425/CS260/assets/71042122/970f4ada-d6b7-4fad-85ed-e1ce96ee32e1)

#### COLLISION :
code in get function
```c++
 if (hashtable[hash_index] == nullptr) { // if nothing
            hashtable[hash_index] = identity;
        } else { // something at index
            person* current = hashtable[hash_index]; 
            while (current->next != nullptr) { // find end of linked list
                current = current->next;
            }
            current->next = identity; // add to end of linked list
        }
```
input

![image](https://github.com/otis425/CS260/assets/71042122/015e2e9b-ae33-4007-a7ec-04d81fb199bd)

output

![image](https://github.com/otis425/CS260/assets/71042122/d87c443d-1740-4ad1-907e-9245ff5e8174)

#### REMOVE :
code
```c++
void remove(std::string key) {
        // Remove the key-value pair from the hashtable
        int index = hash(key);
        if (hashtable[index] == nullptr) {
            return;
        }
        if (hashtable[index]->keyname == key) {
            person* temp = hashtable[index];
            hashtable[index] = hashtable[index]->next;
            delete temp;
            return;
        }
        person* current = hashtable[index];
        while (current->next != nullptr) {
            if (current->next->keyname == key) {
                person* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
```
input

![image](https://github.com/otis425/CS260/assets/71042122/b3c85a1a-78f1-4f78-8bc2-b492ece7cd61)

output

![image](https://github.com/otis425/CS260/assets/71042122/f25563c7-d7d9-432d-9116-87c626418801)

## Collisions on Cost
As collisions increase, our complexity goes up from O(1), and in a worst case scenario, can be O(n). To reduce collisions we want to ensure enough array space, and that our hashing is evenly distributing our inputs accross the data structure. This is an issue because of how we must navigate linked lists one element at a time.


