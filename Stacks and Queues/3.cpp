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

class SetOfStacks {
public:
    SetOfStacks(int maxStackSize) : maxStackSize(maxStackSize) {}

    void push(int data) {
        if(stacks.empty() || stacks.back()->getSize() >= maxStackSize){
            Stack* tempStack = new Stack;

            tempStack->push(data);
            stacks.push_back(tempStack);
        }
        else{
            Stack* tempStack = stacks.back();
            tempStack->push(data);
        }
    }

    void pop() {
        if(!stacks.empty()){
            Stack* tempStack = stacks.back();

            tempStack->pop();
            if(tempStack->isEmpty()) stacks.pop_back();
        }
        else cout << "Stacks are empty" << endl; 
    }

    int peek() {
        if(!stacks.empty()){
            Stack* tempStack = stacks.back();
            return tempStack->peek();
        }
        else {
            cout << "Stacks are empty" << endl;
            return -1;
        }
    }

    void printTopToBottom() {
        cout << "Printing Set of Stacks Top to Bottom" << endl;
        for(int i = stacks.size() - 1; i >= 0; i--){
            cout << "Stack " << i+1 << endl;
            stacks[i]->printTopToBottom();
        }
    }

    void popAtIndex(int i) {
        if( ( stacks.size() - 1 ) < i) {
            cout << "Out of index" << endl;
        }
        else {
            if(stacks[i]->getSize() == 1){
                stacks.erase(stacks.begin() + i);
            }
            else stacks[i]->pop();
        }
    }

private:
    int maxStackSize;
    vector<Stack*> stacks;
};

int main() {
    SetOfStacks myStacks(3);

    myStacks.push(5);
    myStacks.push(1);
    myStacks.push(2);
    myStacks.push(8);
    myStacks.push(151);
    myStacks.push(8231);
    myStacks.push(123124);
    myStacks.push(33);
    myStacks.push(56);

    myStacks.popAtIndex(1);
    myStacks.popAtIndex(1);
    myStacks.popAtIndex(1);
    myStacks.popAtIndex(0);
    myStacks.popAtIndex(1);

    myStacks.printTopToBottom();

    myStacks.popAtIndex(4);

    return 0;
}