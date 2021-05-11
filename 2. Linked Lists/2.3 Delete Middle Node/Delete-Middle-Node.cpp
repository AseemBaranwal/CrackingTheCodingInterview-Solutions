  
/*
 * Cracking the coding interview - edition 6
 * Problem 2.3 : Implement an algorithm to delete a node in the middle of a singly linked list. More than 1 nodes are present
 *
 * Approach:
 * In order to remove a node 'A' from a list, We will need to connect pointer of
 * A's previous node to A's next node. Here we don't have access to previous node.
 * Find Middle Node using slow and fast pointer. We delete N/2 + 1th if even number of nodes are given
 * 
 * Problem Link : https://leetcode.com/problems/middle-of-the-linked-list/
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(1)
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

void deleteMiddle(ListNode *head){
    if(!head) return;
    ListNode *fast = head, *slow = head, *prevOfSlow = new ListNode(-1, head);
    while(fast and fast->next){
        prevOfSlow = prevOfSlow->next;
        slow = slow->next;
        fast = fast->next->next;
    }
    prevOfSlow->next = slow->next;
    delete(slow);
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
    deleteMiddle(head);
    cout << "\nLinked List after middle Removal: ";
    p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
}