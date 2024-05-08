#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class SingleLinkedList {
    public:
        SingleLinkedList() : head(nullptr) {}

        // Add to list tail
        void append(int value) {
            Node* newNode = new Node(value);
            // Check if list is empty
            if(!head){
                head = newNode;
            }
            else{
                // Iterate through the list untill last element (next is null)
                Node* temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void removeSingleValue(int value){
            // Check if list is empty
            if(!head) return;
            // Check if element is in head
            if(head->data == value){
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            // Search element
            Node* temp = head;
            // Check if last element arrived or if we found the element we are looking for
            while(temp->next && temp->next->data != value){
                temp = temp->next;
            }
            // If we found the target node
            if(temp->next){
                Node* target = temp->next;
                temp->next = target->next;
                delete target;
            }
        }

        void removeAllValues(int value){
            // Check if list is empty
            if(!head) return;
            // While to check if element is still in head
            while(head && head->data == value){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            
            // Search element
            Node* temp = head;
            // Check if last element arrived or if we found the element we are looking for
            while(temp->next){
                while(temp->next && temp->next->data != value){
                    temp = temp->next;
                }
                // If we found the target node
                if(temp->next){
                    Node* target = temp->next;
                    temp->next = target->next;
                    delete target;
                }
            }
        }

        // Print list
        void printList() {
            cout << "Full list:" << endl;
            Node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

    private:
        Node* head;
};

int main(){

    SingleLinkedList myList;

    int opt;
    int loop_flag = 1;
    while(loop_flag == 1){
        cout << endl;
        cout << "Select operation:" << endl;
        cout << "1 - Append Number to List" << endl;
        cout << "2 - Print Entire List" << endl;
        cout << "3 - Remove Single Element 'x'" << endl;
        cout << "4 - Remove All Elements 'x'" << endl;
        cout << "0 - Exit" << endl;
        cout << "> ";
        cin >> opt;

        int num;
        switch (opt){
            case 1:
                cout << "Insert number: ";
                cin >> num;
                myList.append(num);
                cout << endl;
                break;
            case 2:
            myList.printList();
                break;     
            case 3:
                cout << "Insert number: ";
                cin >> num;
                myList.removeSingleValue(num);
                cout << endl;
                break;
            case 4:
                cout << "Insert number: ";
                cin >> num;
                myList.removeAllValues(num);
                cout << endl;
                break;
            default:
                loop_flag = 0;
                break;
        }
    }

    return 0;
}