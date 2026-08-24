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
private:
    struct compare{
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       std::priority_queue<ListNode* , vector<ListNode*>, compare> pq;
       ListNode* dummy = new ListNode(0);
       ListNode* tail = dummy;
       for (ListNode* node : lists){
            if(node != nullptr){
                pq.push(node);
            }
       }
       while(!pq.empty()){
            ListNode* top_n = pq.top();
            pq.pop();
            tail->next = top_n;
            tail = tail->next;
            if(top_n->next != nullptr){
                pq.push(top_n->next);
            }
       }
       return dummy->next;
    }
};
