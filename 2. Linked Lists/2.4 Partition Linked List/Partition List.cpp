/*
 * Cracking the coding interview edition 6
 * Problem 2.4 Partition: Write code to partition linked list around a value x, such that
 * nodes less than x come before all the nodes greater than or equal to x.
 * If x is in the list, the values of x only need to be after the elements less than x.
 * Example
 * 3-->5-->8-->5-->10-->2-->1 (x = 5)
 * 3-->1-->2-->10-->5-->5-->8
 *
 * Problem Link: https://leetcode.com/problems/partition-list/
 * 
 * Approach:
 * Start with first node, and add every thing bigger or equal to x at tail and smaller values at head.
 * This is a stable sort algorithm
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
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

ListNode *partition(ListNode *head, int x){
    if(!head) return NULL;
    ListNode *headLeft = new ListNode(-1), *headRight = new ListNode(-1);
    ListNode *left = headLeft, *right = headRight, *curr = head;
    while(curr){
        if(curr->val < x){
            left->next = curr;
            left = left->next;
        }else{
            right->next = curr;
            right = right->next;
        }
        curr = curr->next;
    }
    right->next = NULL;
    left->next = headRight->next;
    return headLeft->next;
}

signed main(){
    cout << "Input number of Nodes: ";
    int n; cin >> n;
    cout << "Input the nodes Value: ";
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
    cout << "\nInput x: ";
    int x; cin >> x;
    head = partition(head, x);
    cout << "\nLinked List after Partition: ";
    p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
}