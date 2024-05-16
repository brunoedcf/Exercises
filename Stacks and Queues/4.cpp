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

class MyQueue {
public:
    MyQueue() : size(0) {}

    void push(int data) {
        size++;
        mainStack.push(data);
    }

    void pop() {
        if(size > 0){
            while(!mainStack.isEmpty()){
                auxStack.push(mainStack.peek());
                mainStack.pop();
            }

            auxStack.pop();

            while(!auxStack.isEmpty()){
                mainStack.push(auxStack.peek());
                auxStack.pop();
            }

            size--;
        }
    }

    void printMyQueue() {
        cout << "Printing Queue from first to last: " << endl;
        while(!mainStack.isEmpty()){
            auxStack.push(mainStack.peek());
            mainStack.pop();
        }

        while(!auxStack.isEmpty()){
            mainStack.push(auxStack.peek());
            cout << auxStack.peek() << " ";
            auxStack.pop();
        }
        cout << endl;
    }

private:
    Stack mainStack;
    Stack auxStack;
    int size;
};

int main() {

    MyQueue testQueue;
    testQueue.push(5);
    testQueue.push(8);
    testQueue.push(11);
    testQueue.push(23);
    testQueue.push(34);
    testQueue.pop();
    testQueue.push(55);

    testQueue.printMyQueue();

    return 0;
}