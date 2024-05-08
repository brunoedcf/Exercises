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

        // Delete middle node
        void deleteMiddleNode(Node* node) {

            Node* temp = node->next;
            node->data = temp->data;
            node->next = temp->next;
            delete temp;

        }

        Node* searchNode(int n) {
            Node* temp = head;
            while(temp){
                if(temp->data == n){
                    return temp;
                }
                else{
                    temp = temp->next;
                }
            }
            return nullptr;
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
    cout << "Searching Kth element..." << endl;
    Node* myNode = myList.searchNode(k);
    cout << "Deleting middle element..." << endl;
    myList.deleteMiddleNode(myNode);
    myList.printList();

    return 0;
}