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

bool checkIntersection1(SingleLinkedList* firstList, SingleLinkedList* secondList) {

    map<Node*, int> myMap;

    Node* firstListHead = firstList->head;
    Node* secondListHead = secondList->head;

    while(firstListHead){
        myMap[firstListHead] = 1;
        firstListHead = firstListHead->next;
    }

    while(secondListHead){
        if(!myMap[secondListHead]){
            myMap[secondListHead] = 1;
        }
        else{
            return false;
        }
        secondListHead = secondListHead->next;
    }

    return true;
}

bool checkIntersection2(SingleLinkedList* firstList, SingleLinkedList* secondList) {

    Node* firstListHead = firstList->head;
    Node* secondListHead = secondList->head;

    while(firstListHead->next){
        firstListHead = firstListHead->next;
    }

    while(secondListHead->next){
        secondListHead = secondListHead->next;
    }

    if(firstListHead != secondListHead) return false;

    return true;
}

int main(){
    return 0;
}