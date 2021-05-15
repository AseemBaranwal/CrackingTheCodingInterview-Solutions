/**
 * Cracking the coding interview edition 6
 * /**
 * Problem 2.7 : Problem 2.7 Intersection
 * Given two linked lists, if they both intersect at some point. Find out the intersecting point else return nullptr.
 * Intersection is defined based on reference not value.
 *
 * Approach : Use the vector to store address, the first time two lists have same address from behind, this is the solution.
 * If no such element is found, no intersecting node is present.
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
    vector<ListNode *> first, second;
    ListNode *p = headA;
    while(p){
        first.push_back(p);
        p = p->next;
    }
    p = headB;
    while(p){
        second.push_back(p);
        p = p->next;
    }
    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());
    int i = 0, mx = min(first.size(), second.size());
    while(i < mx and first[i] == second[i]){
        i++;
    }
    if(i == 0 or (i == mx and first[i-1] != second[i-1])) return NULL;
    return second[i-1];
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