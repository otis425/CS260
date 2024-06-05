#include <iostream>
#include <string>

struct person {
    std::string keyname;
    int amount;
    person* next;

    person() {
        next = nullptr;
        keyname = "";
        amount = 0;
    }
};

struct simple_string_hash {
    person* hashtable[26];

    simple_string_hash() {
        std::fill_n(hashtable, 26, nullptr);
    }

    int hash(std::string key){
        int firstLetter = std::toupper(key[0]) - 'A';
        return firstLetter;
    }

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

    void remove(std::string key) {
        // Remove the key-value pair from the hashtable
        int index = hash(key);
        if (hashtable[index]->keyname != key) {
            return;
        }
        delete hashtable[index];
        hashtable[index] = nullptr; // Set the pointer to nullptr after deletion
    }

    void print_tree(){
        for (int i = 0; i < 26; i++) {
            if (hashtable[i] != nullptr) {
                std::cout << "[" << i << ":(" << hashtable[i]->keyname << "," << hashtable[i]->amount << ")]" ;
            } else {
                std::cout << "[" << i << "]";
            }
        }
        std::cout << std::endl;
    }
};

struct smart_stringhash{
    person* hashtable[26];

    smart_stringhash() {
        std::fill_n(hashtable, 26, nullptr);
    }

    int hash(std::string key){
        int firstLetter = std::toupper(key[0]) - 'A';
        return firstLetter;
    }

    void insert(std::string key, int value) {
        // create person with key-value
        person *identity = new person;
        identity->keyname = key;
        identity->amount = value;
        // place in hashtable
        int hash_index = hash(key);
        if (hashtable[hash_index] == nullptr) { // if nothing
            hashtable[hash_index] = identity;
        } else { // something at index
            person* current = hashtable[hash_index]; 
            while (current->next != nullptr) { // find end of linked list
                current = current->next;
            }
            current->next = identity; // add to end of linked list
        }
    }

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

    void print_tree(){
        for (int i = 0; i < 26; i++) {
            if (hashtable[i] != nullptr) {
                if (hashtable[i]->next != nullptr) {
                     std::cout << "[" << i << ":(" << hashtable[i]->keyname << "," << hashtable[i]->amount << ")+more]" ;
                }
                std::cout << "[" << i << ":(" << hashtable[i]->keyname << "," << hashtable[i]->amount << ")]" ;
            } else {
                std::cout << "[" << i << "]";
            }
        }
        std::cout << std::endl;
    }
};