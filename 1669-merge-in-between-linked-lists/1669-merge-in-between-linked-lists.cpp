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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        ListNode* temp1=list2;
        int i=0;
        while(temp1){
            if(temp1->next==NULL)
                break;
            temp1=temp1->next;
        }
        while(temp){
            if(i==b){
                temp1->next=temp->next;
                break;
            }
            i++;
            temp=temp->next;
        }
        i=1;
        temp=list1;
         while(temp){
            if(i==a){
                temp->next=list2;
                break;
            }
            temp=temp->next;
             i++;
        }
        return list1;
    }
};