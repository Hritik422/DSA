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
    ListNode* ans;
    ListNode* rev(ListNode* head){
        if(head->next==NULL){ans=head;return head;}
        rev(head->next)->next=head;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        rev(head)->next=NULL;
        return ans;
    }
};