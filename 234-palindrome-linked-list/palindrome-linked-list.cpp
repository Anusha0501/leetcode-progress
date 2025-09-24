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
    // Helper function to reverse linked list
    ListNode* reverselinkedlist(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newhead = reverselinkedlist(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        // Step 1: Find middle using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHead = reverselinkedlist(slow->next);

        // Step 3: Compare first and second half
        ListNode* first = head;
        ListNode* second = secondHead;
        bool palindrome = true;
        while (second != NULL) {
            if (first->val != second->val) {
                palindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: Restore list (optional)
        slow->next = reverselinkedlist(secondHead);

        return palindrome;
    }
};
