// ReverseSingleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    static
    ListNode* reverseList(ListNode* head) {      

        ListNode* prev = nullptr;

        while (head) {
            ListNode* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;

        }
        return prev;
    }
};


int main()
{
    ListNode n0(0), n1(1), n2(2), n3(3); 
    n0.next = &n1; n1.next = &n2; n2.next = &n3;

    ListNode* reversed = Solution::reverseList(head);
}
