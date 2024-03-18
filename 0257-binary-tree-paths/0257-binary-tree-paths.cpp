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
    //string temp;
    vector<string>ans;
    void check(TreeNode* root,string temp){
        if(!root)return;
        if(!root->left && !root->right){
            temp+=to_string(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp+=to_string(root->val);
        temp+="->";
        check(root->left,temp);
        check(root->right,temp);
        temp.pop_back();
        temp.pop_back();
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        check(root,"");
        return ans;
    }
};