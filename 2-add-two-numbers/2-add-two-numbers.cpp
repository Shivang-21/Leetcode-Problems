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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode;
        ListNode* ans=temp;
        int carry=0;
        while(l1 || l2)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }                
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }                
            sum+=carry;
            carry=sum/10;
            sum%=10;
            ListNode* t=new ListNode(sum);
            temp->next=t;
            temp=temp->next;            
        }
        if(carry)
        {
            temp->next=new ListNode(carry);
        }
        return ans->next;
    }
};