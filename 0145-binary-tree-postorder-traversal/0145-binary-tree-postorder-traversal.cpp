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
    vector<int> postorderTraversal(TreeNode* head) {
        stack<pair<TreeNode*,int>>st;
    if(head==NULL){
        return {};
    }
        vector<int>ans;
    st.push({head,0});
    while(!st.empty()){
        auto root=st.top().first;
        int flag=st.top().second;
        st.pop();
        if(flag==1){
            ans.push_back(root->val);
            continue;
        }
        st.push({root,flag+1});
        if(root->right)
        st.push({root->right,0});
        if(root->left)
        st.push({root->left,0});
    }
        return ans;
    }
};