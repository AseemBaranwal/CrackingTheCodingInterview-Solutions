/**
 * Cracking the coding interview edition 6
 * /**
 * Problem 2.7 : Problem 2.7 Intersection
 * Given two linked lists, if they both intersect at some point. Find out the intersecting point else return nullptr.
 * Intersection is defined based on reference not value.
 *
 * Approach : We can use two iterations to do that. In the first iteration, we will reset the pointer 
 * of one linkedlist to the head of another linkedlist after it reaches the tail node. In the second iteration, 
 * we will move two pointers until they points to the same node. Our operations in first iteration will help us 
 * counteract the difference. So if two linkedlist intersects, the meeting point in second iteration must be the 
 * intersection point. If the two linked lists have no intersection at all, then the meeting pointer in second iteration 
 * must be the tail node of both lists, which is NULL.
 * 
 * Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA or !headB) return NULL;
    ListNode *p1 = headA, *p2 = headB;
    while(p1 != p2){
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }
    return p1;
}

signed main(){
    cout << "Input number of Nodes in Linked List 1: ";
    int n1; cin >> n1;
    cout << "Input the nodes Value: ";
    int tmp; cin >> tmp; n1--;
    ListNode *head1 = new ListNode(tmp), *p = head1;
    while(n1 --){
        cin >> tmp;
        ListNode *temp = new ListNode(tmp);
        p->next = temp;
        p = p->next;
    }
    cout << "\nThe inputed Linked List 1 is as follows: ";
    p = head1;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }

    cout << "\nInput number of Nodes in Linked List 2: ";
    int n2; cin >> n2;
    cout << "Input the nodes Value: ";
    cin >> tmp; n2--;
    ListNode *head2 = new ListNode(tmp);
    p = head2;
    while(n2 --){
        cin >> tmp;
        ListNode *temp = new ListNode(tmp);
        p->next = temp;
        p = p->next;
    }
    cout << "\nThe inputed Linked List 2 is as follows: ";
    p = head2;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    ListNode *res = getIntersectionNode(head1, head2);
    if(res)
        cout << "\nList has intersecting nodes";
    else
        cout << "\nList doesn't have intersecting nodes";
    return 0;
}