/**
 * Cracking the coding interview edition 6
 * /**
 * Problem 2.6 : Implement a function to check if a list is a palindrome.
 * 
 * Approach : Iterative Approach
 * 							- Push half the list in stack,
 * 							- Compare the rest of the list by popping off from the stack
 * 
 * Problem Link: https://leetcode.com/problems/palindrome-linked-list/
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */

#include<bits/stdc++.h>
using namespace std;

class ListNode{
  public:
    int val;
    ListNode *next = NULL;
    ListNode(int data = 0){
        val = data;
    }
    ListNode(int data, ListNode *next){
        val = data;
        this->next = next;
    }
};

bool checkPalindrome(ListNode *head){
    if(!head or !head->next) return true;
    stack<int> st;
    ListNode *fast = head, *slow = head;
    while(fast and fast->next){
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast)
        slow = slow->next;
    while(slow and st.top() == slow->val){
        st.pop();
        slow = slow->next;
    }
    return slow == NULL;
}

signed main(){
    cout << "Input number of Nodes in Linked List 1: ";
    int n; cin >> n;
    cout << "Input the nodes Value: ";
    int tmp; cin >> tmp; n--;
    ListNode *head = new ListNode(tmp), *p = head;
    while(n --){
        cin >> tmp;
        ListNode *temp = new ListNode(tmp);
        p->next = temp;
        p = p->next;
    }
    cout << "\nThe inputed Linked List 1 is as follows: ";
    p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    bool res = checkPalindrome(head);
    if(res)
        cout << "\nList is a Palindrome";
    else
        cout << "\nList is not a Palindrome";
    return 0;
}