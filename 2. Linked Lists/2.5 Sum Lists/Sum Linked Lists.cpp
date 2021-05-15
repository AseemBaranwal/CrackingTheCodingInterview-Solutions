/**
 * Cracking the coding interview edition 6
 * Problem 2.5 Sum lists: You have two numbers represented by linked list, where each node contains
 * a single digit. Digits are stored in reverse order.(1's digit is at the head)
 * Write a function that adds two such numbers and returns a number in similar list format.
 * Example:
 * 7-->1-->6 + 5-->9-->2 = 2-->1-->9
 * which is (617 + 295  = 912)
 * What if digits are not stored in reverse order(i.e 1's digit is at tail)
 * (6--1-->7) + (2-->9-->5) = (9-->1-->2)
 *
 * Approach:
 * We will solve the problem recursively and iteratively. Add numbers at same digits place, 
 * store the 1's digit of the output in new list and add carry in next place's addition.
 *
 * Problem Link: https://leetcode.com/problems/add-two-numbers/
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

ListNode *sumLists(ListNode *head1, ListNode *head2){
    if(!head1) return head2;
    if(!head2) return head1;
    int carry = 0, curr = 0;
    ListNode *p1 = head1, *p2 = head2, *dummyHead = new ListNode(-1), *p = dummyHead;
    while(p1 or p2 or carry){
        curr = carry;
        if(p1){
            curr += p1->val;
            p1 = p1->next;
        }
        if(p2){
            curr += p2->val;
            p2 = p2->next;
        }
        carry = curr/10, curr = curr%10;
        ListNode *temp = new ListNode(curr);
        p->next = temp;
        p = p->next;
    }
    return dummyHead->next;
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
    ListNode *headRes = sumLists(head1, head2);
    cout << "\nLinked List after Addition: ";
    p = headRes;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}