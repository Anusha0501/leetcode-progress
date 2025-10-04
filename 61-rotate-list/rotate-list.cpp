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

    ListNode* findkthnode(ListNode* temp, int k) {
        for(int i = 1; i < k && temp; i++)
            temp = temp->next;
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        k = k % len;
        if(k == 0) return head;

        // Make it circular temporarily
        tail->next = head;

        ListNode* newLastNode = findkthnode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
