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
