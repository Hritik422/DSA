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
    TreeNode* getRightMostNode(TreeNode* root)
	{
         if(!root->right) { return root;  }
         return getRightMostNode(root->right);
    }
        
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root; 
        if(root->val==key && !root->left && !root->right)return NULL;
        
        if(root->val>key)root->left = deleteNode(root->left,key);
        
        else if(root->val<key)root->right = deleteNode(root->right,key);

        else{                                    
           if(!root->left) {  return root->right;  }
           else if(!root->right) {  return root->left;  }
           else{                                  
              TreeNode* lst = root->left;
              TreeNode* rst = root->right;
              root->left=NULL,root->right=NULL;
              TreeNode* rightMostInLst = getRightMostNode(lst);  
              rightMostInLst->right = rst; 
              return lst;     
           } 
        }
        return root;
    }
};