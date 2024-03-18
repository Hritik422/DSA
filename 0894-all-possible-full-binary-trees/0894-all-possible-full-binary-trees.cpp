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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
       if(n==1){
            res.push_back(new TreeNode(0));
        } 
        else{
            for(int i=1;i<n;i+=2) {
                int l=i,r=n-i-1;
                for (TreeNode* lt : allPossibleFBT(l)) {
                    for (TreeNode* rt : allPossibleFBT(r)) {
                        TreeNode * root = new TreeNode(0);
                        root->left=lt;
                        root->right=rt;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};