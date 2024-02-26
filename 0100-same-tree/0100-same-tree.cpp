/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v1;
    vector<int>v;
    void preorder(TreeNode* p){
         if(p==NULL){
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(p->val);
        preorder(p->left);
        preorder(p->right);
    }
     void preorderr(TreeNode* p){
        if(p==NULL){
            v1.push_back(INT_MIN);
            return;
        }
        v1.push_back(p->val);
        preorderr(p->left);
        preorderr(p->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preorder(p);
        preorderr(q);
        // for(auto it:v)cout<<it<<" ";
        //cout<<endl;
        //for(auto it:v1)cout<<it<<" ";
        if(v.size()!=v1.size())
            return 0;
        for(int i=0;i<v.size();i++)
            if(v[i]!=v1[i])
                return 0;
        return 1;
    }
};