/*
 * Cracking the coding interview edition 6
 * Problem 2.2 : Implement an algorithm to find the kth to last element of a singly linked list.
 * We can assume we are not provided the length of the list. Also k <= size of linked List.
 *
 * Approach: 
 * Use two pointers to get the node at kth index from last.
 * Move pointer1 k times from head. Now move pointer2 and pointer1 together till pointer1 becomes null.
 * Since pointer1 already travelled k distance before, therefore, new distance travelled will be (N-k)
 * Hence pointer2 will be the required Node
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
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

ListNode* findKthNodefromEnd(ListNode *head, int k){
    if(!head) return NULL;
    ListNode *p1 = head, *p2 = head;
    while(p1 and k--){
        p1 = p1->next;
    }
    if(!p1) return head;
    while(p1){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
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
    cout << endl;
    cout << "Input k: ";
    int k; cin >> k;
    ListNode *kthNode = findKthNodefromEnd(head, k);
    if(kthNode)
        cout << "\nThe value at kth node is " << kthNode->val << endl;
    else
        cout << "Wrong input" << endl;
    return 0;
}