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
    void reorderList(ListNode* head) {
        int totalElements = 0;
        ListNode* cur = head;
        while(cur) {
            totalElements++;
            cur = cur->next;
        }

        ListNode* startReverse = head;
        int idxReverse = totalElements - totalElements/2; // correct
        int counter = 0;
        while(startReverse) {
            ListNode tmp(*startReverse);
            if(counter + 1 == idxReverse) { startReverse->next = nullptr; }
            startReverse = tmp.next;
            counter++;
            if(counter == idxReverse) break;
        } // correct value obtained
        
        // Reverse second list
        cur = startReverse;
        ListNode* headReverse = nullptr;
        while(cur) {
            ListNode* nextNode = cur->next;
            cur->next = headReverse;
            headReverse = cur;
            cur = nextNode;            
        }

        // Merge
        while(head && headReverse) { // length(head) >= length(headReverse), max d 1
            ListNode origHead(*head);
            head->next = headReverse;
            head = head->next;
            headReverse = headReverse->next;
            head->next = origHead.next;
            head = head->next;
        }

    }
};

/*
first -> last -> second -> second last -> etc


Idea 1: Copy into reversed list -> pass alternating
[2, 4,6,8,10]
=>
[2, 4, 6]
 |
[10, 8]
 |
=> 2, 10

[2, 4, 6]
    |
[10, 8]
     |
=> 2, 10, 



2 -> 10 -> 4 -> 8 -> 6

Idea 2:
First Element in #1

Keep copy of orig next element
Run to end of list, take last, set as next of cur.
Next element is the copy of orig.

[2,4,6,8]

[2,8,4,6]

*/


