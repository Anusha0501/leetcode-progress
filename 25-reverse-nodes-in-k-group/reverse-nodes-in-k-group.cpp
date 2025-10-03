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
    // Helper to reverse a portion of the list [start, end)
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while (curr != end) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // New head of reversed segment
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;
            // Move kth to the k-th node from prevGroupEnd
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break; // Less than k nodes left, stop

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            // Reverse current k-group
            ListNode* newGroupHead = reverse(groupStart, nextGroupStart);

            // Connect previous part with reversed group
            prevGroupEnd->next = newGroupHead;
            groupStart->next = nextGroupStart;

            // Move prevGroupEnd pointer to end of reversed group
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
