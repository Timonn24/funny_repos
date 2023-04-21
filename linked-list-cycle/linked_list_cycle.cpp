// LinkedListCycle.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
#include <unordered_map>


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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) 
            return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) 
                return true;
        }
        return false;
    }
    
};

int main()
{
    ListNode n1(0);
    ListNode n2(1); n1.next = &n2;
    ListNode n3(2); n2.next = &n3;
    ListNode n4(3); n3.next = &n4;
    n4.next = &n1;

    bool has = Solution::hasCycle(&n1);
}