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
    ListNode* beg;
    bool rev(ListNode* head){
        cout<<head->val<<endl;
        if(head->next==NULL){
            //ListNode* cur=beg;
            if(head->val==beg->val){
                beg=beg->next;
                return 1;
            }
            return 0;
        }
        if(!rev(head->next))return 0;
        if(head->val!=beg->val){return false;}
        beg=beg->next;
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        beg=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return rev(slow);
    }
};