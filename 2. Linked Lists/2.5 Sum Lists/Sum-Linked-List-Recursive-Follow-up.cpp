/**
 * Cracking the coding interview edition 6
 * Problem 2.5 Sum lists: You have two numbers represented by linked list, where each node contains
 * a single digit. Digits are stored in reverse order.(1's digit is at the head)
 * Write a function that adds two such numbers and returns a number in similar list format.
 * Example:
 * 1-->2-->3-->4 + 5-->6-->7 = 1-->8-->0-->1
 * which is (1234 + 567 = 1802)
 * 
 * Problem Link: https://leetcode.com/problems/add-two-numbers/
 *
 * Approach:
 * We will solve the problem Follow up, ie the listNodes are given as numbers in the same order.
 * In case of shorter and longer lists, our solution may fail --> find lengths of both lists.
 * Fill up the shorter list head with zeros by inserting zeros at head of list
 * Now perform addition
 * 
 * Time Complexity : O(N + M)
 * Space Complexity : O(M + N)
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

void display(ListNode *head){
    ListNode *p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

inline int findLen(ListNode *head, int res = 0){
    while(head){
        res++;
        head = head->next;
    }
    return res;
}

ListNode *insertAtHead(ListNode *head, int num){
    ListNode *tmp = new ListNode(num, head);
    head = tmp;
    return head;
}

ListNode *padList(ListNode *head, int len){
    while(len--){
        head = insertAtHead(head, 0);
    }
    return head;
}

ListNode *sumListsUtil(ListNode *head1, ListNode *head2, int &carry){
    if(!head1 and !head2 and !carry)
        return NULL;
    ListNode *head = sumListsUtil((head1? head1->next: NULL), (head2? head2->next: NULL), carry);
    int curr = carry + (head1? head1->val: 0) + (head2? head2->val: 0);
    head = insertAtHead(head, curr%10);
    carry = curr/10;
    return head;
}

ListNode *sumLists(ListNode *head1, ListNode *head2){
    int len1 = findLen(head1), len2 = findLen(head2), carry = 0;
    if(len1 < len2)
        head1 = padList(head1, len2-len1);
    else
        head2 = padList(head2, len1-len2);
        
    ListNode *head = sumListsUtil(head1, head2, carry);
    if(carry)
        head = insertAtHead(head, carry);
    return head;
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
    display(head1);

    cout << "Input number of Nodes in Linked List 2: ";
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
    display(head2);

    ListNode *headRes = sumLists(head1, head2);
    cout << "\nLinked List after Addition: ";
    display(headRes);
    return 0;
}