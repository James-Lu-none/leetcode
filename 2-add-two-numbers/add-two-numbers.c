/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    while(l1 || l2 || (carry!=0)) {
        int a = 0;
        int b = 0;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(l1) {
            a = l1->val;
            l1 = l1->next;
        }
        if(l2) {
            b = l2->val;
            l2 = l2->next;
        }
        
        sum = (a+b+carry)%10;
        newNode->val = sum;
        newNode->next = NULL;
        carry = (a+b+carry>9)?1:0;
        if(head==NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}