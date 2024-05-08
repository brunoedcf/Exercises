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

        void partition(int x){

            Node* leftHead = nullptr;
            Node* leftCurrent = nullptr;
            Node* rightHead = nullptr;
            Node* rightCurrent = nullptr;

            Node* current = head;
            while(current){
                Node* newNode = new Node(current->data);

                if(newNode->data < x){
                    if(!leftHead){
                        leftHead = newNode;
                        leftCurrent = newNode;
                    }
                    else{
                        leftCurrent->next = newNode;
                        leftCurrent = newNode;
                    }
                }
                else{
                    if(!rightHead){
                        rightHead = newNode;
                        rightCurrent = newNode;
                    }
                    else{
                        rightCurrent->next = newNode;
                        rightCurrent = newNode;
                    }
                }
                
                current = current->next;
            }

            head = leftHead;
            leftCurrent->next = rightHead;
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
    
    int k;
    cin >> k;

    myList.printList();
    myList.partition(k);
    myList.printList();

    return 0;
}