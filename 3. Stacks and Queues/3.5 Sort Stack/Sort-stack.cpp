/* Cracking The Coding Interview 6
 * Problem 3.5 : Sort Stack: Write a program to sort a stack such that the smallest items are on the top.
 * You can use an additional temporary stack, but you may not copy the elements into any other 
 * data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
 * 
 * Problem Link : https://practice.geeksforgeeks.org/problems/sort-a-stack/1
 * 
 * Time Complexity : O(N*N)
 * Space Complexity : O(N) Recursive
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s){
    while (!s.empty()){
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main(){
    int t;
    cin>>t;
    while(t--){
        SortedStack *ss = new SortedStack();
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}
void insert(stack<int> &st, int ele){
    if(st.size() == 0 or st.top() <= ele){
        st.push(ele);
        return;
    }
    int last = st.top(); st.pop();
    insert(st, ele);
    st.push(last);
}

void SortedStack :: sort(){
   //Your code here
   if(s.size() <= 1) return;
   int last = s.top(); s.pop();
   sort();
   insert(s, last);
}