#include <iostream>
#include <typeinfo>
using namespace std;

struct LNode {
    int data;
    LNode * next;
    LNode(int d) {
        data = d;
        next = nullptr;
    };
};

struct LList {
    int size;
    LNode * head;

    LList (int d) {
        head = new LNode(d);
        size = 1;
    }

    void add_node(int d) {
        LNode * temp = head;
        LNode * new_node = new LNode(d);
        if (d < temp->data) {
            new_node->next = head;
            head = new_node;
        } else {
            while (temp->next != nullptr && d > temp->next->data) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        size++;
    }

    void remove_node(int d) {
        LNode * temp = head;
        LNode * prev = nullptr;
        // find node
        while (temp != nullptr && temp->data != d) {
            prev = temp;
            temp = temp->next;
        }
       // no node
        if (temp == nullptr) {
            cout << "Node not found" << endl;
            return;
        }
        // head node
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        size--;
    }

    void print_list() {
        LNode * temp = head;
        // iterate through list printing untill nullptr
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

};


int main() {
    cout << "creating list with data 10 at head \n";
    LList list(10);
    cout << "~~ add tests ~~ \n";
    cout << "list size = " << list.size << "\n";
    cout << "adding node of 1 \n";
    list.add_node(1);
    cout << "adding node of 5 \n";
    list.add_node(5);
    cout << "current list = ";
    list.print_list();
    cout << "adding node of 3 \n";
    list.add_node(3);
    cout << "current list = ";
    list.print_list();
    cout << "adding second node of 5 \n";
    list.add_node(5);
    cout << "current list = ";
    list.print_list();

    cout << "~~ remove tests ~~ \n";
    cout << "removing node of 3 \n";
    list.remove_node(3);
    cout << "current list = ";
    list.print_list();
    cout << "removing node of 10 \n";
    list.remove_node(10);
    cout << "current list = ";
    list.print_list();
    cout << "removing node of 1 \n";
    list.remove_node(1);
    cout << "current list = ";
    list.print_list();
    return 0;
};