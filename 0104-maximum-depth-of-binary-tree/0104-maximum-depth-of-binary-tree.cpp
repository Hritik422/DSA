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
    queue<TreeNode*>q;
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            cnt++;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            }
        }
        return cnt;
    }
};