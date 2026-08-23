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
        int i = 0 ;
        ListNode* curr = head;
        while(curr != nullptr){
            i++;
            curr = curr->next;
        }
        if( i == n){
            return head->next;
        }
        curr = head;
        for(int j = 0 ; j < (i - n - 1) ; j++){
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return head;
    }
};
