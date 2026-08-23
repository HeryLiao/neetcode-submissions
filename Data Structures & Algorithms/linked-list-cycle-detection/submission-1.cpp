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
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode* sl = head;
        ListNode* fa = head;
        while( fa != nullptr && fa->next != nullptr){
            sl = sl->next;
            fa = fa->next->next;
            if(sl == fa){
                return true;
            }
        }
        return false;
    }
};
