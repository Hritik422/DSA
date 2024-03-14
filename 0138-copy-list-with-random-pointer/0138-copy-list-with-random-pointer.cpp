/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* temp=head;
        Node* tem= new Node(temp->val);
        Node* res=tem;
        map<Node*,Node*>mp;
        while(temp){
                mp[temp]=tem;
                temp=temp->next;
                if(temp)
                tem->next=new Node(temp->val);
                tem=tem->next;
        }
        temp=head;
        int i=0;
        while(temp){
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        return res;
    }
};