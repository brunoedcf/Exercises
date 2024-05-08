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
            cout << "Full list:" << endl;
            Node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        Node* head;
};

SingleLinkedList sumLists(SingleLinkedList first, SingleLinkedList second){

    SingleLinkedList sumList;
    Node* currentFirst = first.head;
    Node* currentSecond = second.head;
    Node* stopNode = new Node(0);
    int remainder = 0;

    while(true){
        int numbersSum = currentFirst->data + currentSecond->data + remainder;
        remainder = 0;

        if(numbersSum >= 10){
            remainder = 1;
            sumList.append(numbersSum - 10);
        }
        else{
            sumList.append(numbersSum);
            remainder = 0;
        }

        if(!currentFirst->next || currentFirst == stopNode){
            currentFirst = stopNode;
        } 
        else{
            currentFirst = currentFirst->next;
        }
        if(!currentSecond->next || currentSecond == stopNode){
            currentSecond = stopNode;
        } 
        else{
            currentSecond = currentSecond->next;
        }

        if(currentFirst == stopNode && currentSecond == stopNode) break;
    }

    return sumList;
}

int main(){
    SingleLinkedList first;
    SingleLinkedList second;

    int fistSize;
    cin >> fistSize;
    for(int i = 0; i < fistSize; i++){
        int element;
        cin >> element;
        first.append(element);
    }

    int secondSize;
    cin >> secondSize;
    for(int i = 0; i < secondSize; i++){
        int element;
        cin >> element;
        second.append(element);
    }

    first.printList();
    second.printList();

    SingleLinkedList sum = sumLists(first, second);
    sum.printList();

    return 0;
}