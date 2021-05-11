/*
 * Cracking the coding interview edition 6
 * Problem 2.1 : Remove duplicates from an unsorted linked list.
 * 
 * Approach : Using a linear algorithm that takes care of node to be deleted since C++ doesn't have implicit deletion
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 * 
 * Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/
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

void removeDups(ListNode *head){
    if(!head) return;
    ListNode *p = head;
    while(p){
        ListNode *tmp = p;
        if(p->next and p->val == p->next->val){
            tmp = p->next;
            p->next = tmp->next;
            delete(tmp);
        }else{
            p = p->next;
        }
    }
}

signed main(){
    int n; cin >> n;
    int tmp; cin >> tmp;
    n--;
    ListNode *head = new ListNode(tmp), *p = head;
    while(n --){
        cin >> tmp;
        ListNode *temp = new ListNode(tmp);
        p->next = temp;
        p = p->next;
    }
    cout << "\nThe inputted Linked List is as follows: ";
    p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    removeDups(head);
    cout << "\nLinked List after duplicate Removal: ";
    p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
}