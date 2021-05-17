/*
 * Cracking the Coding Interview
 *
 * Problem 3.1 : Implement a tri-stack using a single array
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class FixedMutiStack{

  private:
    int numStacks = 3;
    int capacity;
    int *values;
    int *sizes;

  public:
    FixedMutiStack(int cap){
        this->capacity = cap;
        this->values = new int[cap * numStacks];
        this->sizes = new int[numStacks];
    }
    void push(int stackNum, int data){
        if(isFull(stackNum)){
            cout << "Current stack " << stackNum << " is full" << endl;
            return;
        }
        sizes[stackNum]++;
        values[topIndex(stackNum)] = data;
    }
    int pop(int stackNum){
        if(isEmpty(stackNum)){
            cout << "Current Stack " << stackNum << " is empty\n";
            return -1;
        }
        int value = values[topIndex(stackNum)];
        sizes[stackNum]--;
        return value;
    }
    int peek(int stackNum){
        if(isFull(stackNum)){
            cout << "Current stack " << stackNum << " is full" << endl;
            return -1;
        }
        return values[topIndex(stackNum)];
    }
    bool isFull(int stackNum){
        return sizes[stackNum] == capacity;
    }
    bool isEmpty(int stackNum){
        return sizes[stackNum] == 0;
    }
    int topIndex(int stackNum){
        int offset = stackNum*capacity;
        return offset + sizes[stackNum] - 1;
    }
    void printAll(){
        for(int i = 0; i < numStacks; i++){
            cout << "\nStack " << i << ": ";
            for(int j = 0; j < capacity; j++){
                cout << values[i*capacity + j] << " ";
            }
        }
        cout << endl;
    }
};
int main(){
    cout << "Enter the capacity of the stack: ";
    int cap, num; cin >> cap;
    FixedMutiStack stack(cap);
    cout << "\nEnter the stack to work with else 0 to break" << endl;
    while(cin >> num, num>0){
    	num--;
        cout << "1.Push 2.Pop 3.Peek : ";
        int choice, data, val; cin >> choice;
        switch(choice){
            case 1:
                cin >> data;
                stack.push(num, data); 
                break;
            
            case 2:
                val = stack.pop(num);
                if(val != -1)
                    cout << "The popped element is " << val << endl;
                break;

            case 3:
                val = stack.peek(num);
                if(val != -1)
                    cout << "The Top element is " << val << endl;
                break;
            default:
                cout <<"Wrong Statement \n";
        }
        stack.printAll();
        cout << "\nEnter the stack to work with else 0 to break" << endl;
        cin.clear();
    }
    stack.printAll();
    return 0;
}