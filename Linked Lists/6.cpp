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

        void checkPalindrome(SingleLinkedList* backwards) {
            recursivePass(head, backwards);
            printList();
            backwards->printList();
            cout << checkEqual(head, backwards->head) << endl;

            return;
        }

        void recursivePass(Node* current_head, SingleLinkedList* backwards){
            if(current_head->next){
                recursivePass(current_head->next, backwards);
            }
            backwards->append(current_head->data);
            
            return;
        }

        bool checkEqual(Node* first_head, Node* second_head) {
            Node* first_temp = first_head;
            Node* second_temp = second_head;
            while(first_temp && second_temp){
                if(first_head->data != second_head->data) return false;
                first_temp = first_temp->next;
                second_temp = second_temp->next;
            }
            return true;
        }

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

    SingleLinkedList backwards;
    myList.checkPalindrome(&backwards);

    return 0;
}