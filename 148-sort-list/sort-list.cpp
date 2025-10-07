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
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l1) ? l1 : l2;
        return dummy.next;
    }
    
    // Function to find the middle of the list using slow-fast pointers
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves
        if (prev) prev->next = nullptr;
        return slow;
    }
    
    // Merge Sort for linked list
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* mid = getMiddle(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
};
