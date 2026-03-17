/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recursive(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* rest = recursive(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
    ListNode* reverseList(ListNode* head) {
        // return recursive(head);
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }
        return prev;
    }
};