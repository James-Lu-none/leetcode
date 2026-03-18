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
    ListNode* reverseList(ListNode* head) {
        // from 206. Reverse Linked List
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        int counter = 0;
        ListNode* curr = head;
        ListNode* groupHead = head;
        ListNode* prevGroupEnd = nullptr;

        while (curr) {
            counter++;
            ListNode* nextNode = curr->next;
            if (counter % k == 0) {
                curr->next = nullptr;
                // groupHead is for group n, it will point to last node in group n after reverse list
                // newHead is for group n
                // prevGroupEnd is for group n-1
                ListNode* newHead = reverseList(groupHead);

                // ListNode* test = newHead;
                // while (test) {
                //     printf("%d ",test->val);
                //     test = test->next;
                // }
                // printf("\n");
                // printf("prevGroupEnd val: %d\n",prevGroupEnd->val);
                // printf("group n lastNode val: %d\n",groupHead->val);

                if (prevGroupEnd == nullptr) {
                    head = newHead;
                } else {
                    // connect group n-1 's tail to group n's newHead
                    prevGroupEnd->next = newHead;
                }
                // connect group n's tail to nextNode
                groupHead->next = nextNode;
                // set group n-1's tail to group n's tail for next loop
                prevGroupEnd = groupHead;
                // set groupHead for group n+1 to nextNode and resume curr
                groupHead = nextNode;
                curr = nextNode;
            } else {
                curr = nextNode;
            }
        }
        return head;
    }
};