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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head; 
        
        ListNode* prevGroupNode = dummy;
        while(true){
            //find kth node
            ListNode* kthnode = prevGroupNode;
            for(int i = 0; i<k; i++){
                kthnode = kthnode->next;
                if(!kthnode){
                    return dummy->next;
                }
            }

            //reverse
            ListNode* nextGroupNode = kthnode->next;

            ListNode* prev = nextGroupNode;
            ListNode* cur = prevGroupNode->next;

            while(cur!=nextGroupNode){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }      

            ListNode* temp = prevGroupNode->next;
            prevGroupNode->next = kthnode;

            prevGroupNode = temp;
        }

        return dummy->next;
    }
};
