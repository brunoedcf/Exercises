#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* previous;

    int currentMin;

    Node(int data) : data(data), previous(nullptr), currentMin(data) {}
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

            if(top->previous){
                top->currentMin = min(top->data, top->previous->data);
            }
            else {
                top->currentMin = top->data;
            }
        }

        void pop() {
            Node* temp = top;
            top = top->previous;
            delete temp;
        }

        int peek() {
            return top ? top->data : -1;
        }

        int minimum() {
            return top ? top->currentMin : -1;
        }

        Node* top;
};


int main(){

    Stack myStack;

    cout << myStack.minimum() << endl;
    myStack.push(5);
    cout << myStack.minimum() << endl;
    myStack.push(2);
    cout << myStack.minimum() << endl;
    myStack.pop();
    cout << myStack.minimum() << endl;
    myStack.push(2);
    myStack.push(7);
    cout << myStack.minimum() << endl;

    return 0;
}