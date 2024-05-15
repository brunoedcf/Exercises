#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* previous;

    Node(int data) : data(data), previous(nullptr) {}
};

class Queue {
    public:
        Queue() : first(nullptr), last(nullptr) {}

        bool isEmpty() {
            return (first == nullptr && last == nullptr) ? true : false;
        }

        void push(int data) {
            Node* newNode = new Node(data);
            if(first == nullptr && last == nullptr){
                first = newNode;
                last = newNode;
            }
            else{
                last->previous = newNode;
                last = newNode;
            }
        }

        void pop() {
            Node* temp = first;
            first = first->previous;
            delete temp;
        }

        int peekFirst() {
            return first ? first->data : NULL;
        }

        int peekLast() {
            return last ? last->data : NULL;
        }

        Node* first;
        Node* last;
}


int main(){
    return 0;
}