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

        // Print list
        void printList() {
            Node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
       
        Node* head;
};

Node* loopDetection(SingleLinkedList* myList){
    map<Node*, int> myMap;
    Node* myListHead = myList->head;

    while(myListHead){

        if(!myMap[myListHead]){
            myMap[myListHead] = 1;
        }
        else{
            return myListHead;
        }

        myListHead = myListHead->next;
    }

    return nullptr;
}

int main(){
    return 0;
}