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
    void traverse(ListNode* head,int &Max) {
        if(!head->next) {
            Max=max(Max,head->val);
            return;
        }
        traverse(head->next,Max);
        if(head->val<Max) {
            head->val=head->next->val;
            head->next=head->next->next;
        }
        else {
            Max=max(Max,head->val);    
        }        
    }
    ListNode* removeNodes(ListNode* head) {
        int Max=-1;
        traverse(head,Max);
        return head;
    }
};