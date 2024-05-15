#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* previous;

    Node(int data) : data(data), previous(nullptr) {}
};

class Stack {
public:
    Stack() : top(nullptr), size(0) {}

    bool isEmpty() {return top == nullptr;}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->previous = top;
        top = newNode;
        size++;
        // cout << "Element " << top->data << " added to stack" << endl;
    }

    void pop() {
        if (top) {
            Node* temp = top;
            top = top->previous;
            // cout << "Element " << temp->data << " removed from stack" << endl;
            delete temp;
            size--;
        }
        // else cout << "Stack is already empty" << endl;
    }

    int peek() {return top ? top->data : -1;}

    int getSize() {return size;}

    void printTopToBottom() {
        cout << "Printing top to bottom:" << endl;
        Stack tempStack;

        while(top){
            tempStack.push(top->data);
            cout << top->data << " ";
            pop();
        }
        cout << endl;

        while(!tempStack.isEmpty()){
            push(tempStack.peek());
            tempStack.pop();
        }
    }

    void printBottomToTop() {
        cout << "Printing bottom to top:" << endl;
        Stack tempStack;

        while(top){
            tempStack.push(top->data);
            pop();
        }
        
        while(!tempStack.isEmpty()){
            push(tempStack.peek());
            cout << top->data << " ";
            tempStack.pop();
        }
        cout << endl;
    }

    void clear() {
        while(top){pop();}
        cout << "Stack cleared" << endl;
    } 

private:
    Node* top;
    int size;
};

int main(){
    return 0;
}