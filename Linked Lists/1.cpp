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

        void removeDuplicates() {
            map<int, int> myMap;
            Node* temp = head;
            if(!temp){
                return;
            }

            myMap[temp->data] = 1;

            while(temp->next){
                if(myMap[temp->next->data] >= 1){
                    Node* aux = temp->next;
                    temp->next = aux->next;
                    delete aux;
                }
                else{
                    myMap[temp->next->data] = 1;
                    temp = temp->next;
                }
            }
        }

    private:
        Node* head;
};

int main(){
    SingleLinkedList myList;
    int totalElements;
    cin >> totalElements;

    for(int i = 0; i < totalElements; i++){
        int element;
        cin >> element;
        myList.append(element);
    }
    myList.printList();
    cout << "Removing duplicates..." << endl;
    myList.removeDuplicates();
    myList.printList();

    return 0;
}