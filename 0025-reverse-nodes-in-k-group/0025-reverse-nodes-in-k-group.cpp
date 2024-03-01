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
        if(k==1)return head;
        struct ListNode*  temp,*temp1,*temp2,*start,*connect,*fin;
        connect=head;
        temp=head;
        temp1=temp;
        start=head;
        int ans=0,cnt=0,ans1;
        while(temp){
            cnt++;
            if(cnt==k){
                ans++;
                cnt=0;
            }
            temp=temp->next;
        }
        ans1=ans;
        cnt=1;
        temp=head;
        temp=temp->next;

        while(temp){
            cnt++;
            if(cnt<=k){
               temp2=temp->next;
               temp->next=temp1;
               temp1=temp;
            }
            if(cnt==k){
                ans--;
                if(ans+1==ans1){
                    fin=temp1;
                }
                connect->next=temp1;
                connect=start;
                if(ans==0){
                    start->next=temp2;
                    return fin;
                }
                cnt=1;
                start=temp2;
                temp2=temp2->next;
                temp1=start;
            }
            temp=temp2;
          
        }
        return fin;

    }
};