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
    struct compare{
        bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(ListNode* node : lists){
            if(node){
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            cur->next = node;
            cur = cur->next;
            if(node->next){
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
