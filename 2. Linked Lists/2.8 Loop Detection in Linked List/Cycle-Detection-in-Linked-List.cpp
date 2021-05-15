/**
 * Cracking the coding interview, edition 6
 * Problem 2.8 Loop Detection : Determine if a linkedlist has a loop. If it has a loop, find the start of loop.
 * 
 * Approach : Use two pointers, walker and runner. Walker moves step by step, runner moves two steps at time.
 * If the Linked List has a cycle walker and runner will meet at some point.
 * 
 * Problem Link : https://leetcode.com/problems/linked-list-cycle/
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

ListNode* hasCycle(ListNode *head){
    if(!head or !head->next) return NULL;
    ListNode *slow = head, *fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(!fast or !fast->next) return NULL;
    fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    ListNode *res = hasCycle(head);
    if(res)
        cout << "\nList contains a cycle at node " << res->val;
    else
        cout << "\nList doesn't contain a cycle";
    return 0;
}