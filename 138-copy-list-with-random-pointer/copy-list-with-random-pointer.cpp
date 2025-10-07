/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Insert copied nodes after each original node
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Copy random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied lists
        curr = head;
        Node* pseudoHead = new Node(0);
        Node* copyCurr = pseudoHead;
        
        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next; // restore original list
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return pseudoHead->next;
    }
};
