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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // function from 21-merge-two-sorted-lists
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        if (list1->val < list2->val){
            head = list1;
            tail = list1;
            list1 = list1 -> next;
        } else {
            head = list2;
            tail = list2;
            list2 = list2 -> next;
        }
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1 != nullptr) tail->next = list1;
        if (list2 != nullptr) tail->next = list2;
        return head;
    }
    ListNode* getMid(ListNode* head) {
        ListNode* x1 = head;
        // start from head here (ListNode* x2 = head;) will cause infinite recursive call:
        // for example: [x, y]
        // x1 = x1->next will be executed so gitMid will return y as mid, and if split at y, left will be [] and right will be [x, y]
        // which 
        ListNode* x2 = head->next;
        while (x2 != nullptr && x2->next != nullptr) {
            x1 = x1->next;
            x2 = x2->next->next;
        }
        return x1;
    }
    ListNode* sortList(ListNode* head) {
        // return if no node or only one node
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        
        // cut the link bettween left and right linked list
        mid->next = nullptr;
        
        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};