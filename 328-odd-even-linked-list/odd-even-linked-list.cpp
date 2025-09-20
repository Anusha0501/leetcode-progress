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
    ListNode* oddEvenList(ListNode* head) {
        // Edge cases: 0 or 1 node
        if (!head || !head->next) return head;

        ListNode* odd = head;            // pointer for odd indexed nodes
        ListNode* even = head->next;     // pointer for even indexed nodes
        ListNode* evenHead = even;       // store start of even list

        // Rearrange nodes
        while (even && even->next) {
            odd->next = even->next;      // link odd -> next odd
            odd = odd->next;             // move odd pointer

            even->next = odd->next;      // link even -> next even
            even = even->next;           // move even pointer
        }

        // attach even list after odd list
        odd->next = evenHead;
        return head;
    }
};
