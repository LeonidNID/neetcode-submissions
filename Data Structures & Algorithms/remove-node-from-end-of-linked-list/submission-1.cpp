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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        
        // Get size of list
        int size = 0;
        ListNode* cur = head;
        while(cur) {
            size++;
            cur = cur->next;
        }

        // remove given node
        int removeNodeIdx = size - n; // (0 indexed)
        if(removeNodeIdx == 0) return head->next;
        //cout << "removeNodeIdx: " << removeNodeIdx << "\n";
        int counter = 0;
        cur = head;
        while (cur) {
            if (counter + 1 == removeNodeIdx) {
                //cout << "Flag\n";
                if (cur->next != nullptr) {
                    cur->next = cur->next->next;
                }
            }

            counter++;
            cur = cur->next;
        }

        return head;
    }
};

/*
[1,2,3,4]

idx = size - n 
nth node = idx + 1
4 - 2  => 2

*/
