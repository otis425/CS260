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

    void add_nodeat(int pos, int d) {
        // check range of array
        if (pos > size || pos < 0) {
            cout << "position out of range \n";
            return;
        }

        LNode * new_node = new LNode(d);
        if (pos == 0) {
            new_node->next = head;
            head = new_node;
        } else { // pos > 0 do next pointer surgery
            LNode * temp = head;
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        size++;
    }

    void remove_nodeat(int pos) {
        LNode * temp = head;
        // get correct node to delete
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        // do pointer surgery
        LNode * to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
        size--;
    }

    LNode* retrieve_nodeat(int pos) {
        LNode * temp = head;
        // get correct node to retrieve
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp;
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
    cout << "creating list with data 0 at head \n";
    LList list(0);
    cout << "~~ add tests ~~ \n";
    cout << "list size = " << list.size << "\n";
    cout << "adding node at 1 \n";
    list.add_nodeat(1, 1);
    cout << "list size = " << list.size << "\n";
    cout << "adding node at 2 \n";
    list.add_nodeat(2, 2);
    cout << "list size = " << list.size << "\n";
    cout << "adding node at 3 \n";
    list.add_nodeat(3, 3);
    cout << "list size = " << list.size << "\n";
    cout << "current list : ";
    list.print_list();
    cout << "adding node at 1 \n";
    list.add_nodeat(1, 10);
    cout << "current list : ";
    list.print_list();
    cout << "adding node at 1 \n";
    list.add_nodeat(1, 5);
    cout << "current list : ";
    list.print_list();
    cout << "list size = " << list.size << "\n";
    cout << "~~ retrieve tests ~~ \n";
    for (int i = 0; i < list.size; i++) {
        int node_val = list.retrieve_nodeat(i)->data;
        cout << "node at " << i << " = " << node_val << "\n";
    }
    cout << "~~ remove tests ~~ \n";
    cout << "current list : ";
    list.print_list();
    cout << "removing node at 1 \n";
    list.remove_nodeat(1);
    cout << "current list : ";
    list.print_list();
    cout << "removing node at 2 \n";
    list.remove_nodeat(2);
    cout << "current list : ";
    list.print_list();

    return 0;
};