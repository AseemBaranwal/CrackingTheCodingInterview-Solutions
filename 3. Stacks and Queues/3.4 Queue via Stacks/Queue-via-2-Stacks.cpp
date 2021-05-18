/* Cracking the coding interview 6
 * Problem 3.3 : Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.
 * 
 * Problem Link : https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#
 * 
 * Push : O(1)
 * Pop : O(N) Worst O(1) Average
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class StackQueue{
    private:   
        // These are STL stacks ( http://goo.gl/LxlRZQ )
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int);
        int pop();
    void StackQueue :: push(int x){
        s1.push(x);
    }
};

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    if(s2.empty()){
        while(!s1.empty()){
            int tmp = s1.top(); s1.pop();
            s2.push(tmp);
        }
    }
    if(s2.empty()) return -1;
    int res = s2.top(); s2.pop();
    return res;
}
