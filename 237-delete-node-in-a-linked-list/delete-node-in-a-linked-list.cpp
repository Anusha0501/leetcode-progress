/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Copy the next node's value into the current node
        node->val = node->next->val;

        // Step 2: Store the node to be deleted (which is the next node)
        ListNode* temp = node->next;

        // Step 3: Bypass the next node
        node->next = node->next->next;

        // Step 4: Free memory of the deleted node
        delete temp;
    }
};
