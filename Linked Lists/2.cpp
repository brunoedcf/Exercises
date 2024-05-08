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


        void searchKthToLastElement(int k){
            recursionCounter = 0;
            recursiveSearch(head, k);

            return;
        }

        void recursiveSearch(Node* current_head, int k){
            if(current_head){
                recursiveSearch(current_head->next, k);
                if(recursionCounter == k){
                    cout << current_head->data << endl;
                }
            }
            recursionCounter++;
            
            return;
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
        int recursionCounter;
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
    cout << "Searching Kth to last element..." << endl;
    myList.searchKthToLastElement(k);

    return 0;
}