#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* previous;

    Node(int data) : data(data), previous(nullptr) {}
};

class Stack {
    public:
        Stack() : top(nullptr) {}

        bool isEmpty() {
            return top == nullptr ? true : false;
        }

        void push(int data) {
            Node* newNode = new Node(data);
            newNode->previous = top;
            top = newNode;
        }

        void pop() {
            Node* temp = top;
            top = top->previous;
            delete temp;
        }

        int peek() {
            return top ? top->data : -1;
        }

        Node* top;
};


int main(){

    Stack stack_array[3];

    stack_array[0].push(1);
    stack_array[1].push(2);
    stack_array[2].push(3);
    stack_array[0].push(4);
    stack_array[1].push(5);
    stack_array[2].push(6);

    return 0;
}