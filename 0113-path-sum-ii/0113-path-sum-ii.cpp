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
    vector<vector<int>>ans;
    void check(TreeNode* root,vector<int>temp,int target){
        if(!root)return;
        if(!root->left && !root->right && target==root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        check(root->left,temp,target-root->val);
        check(root->right,temp,target-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        check(root,{},targetSum);
        return ans;
    }
};