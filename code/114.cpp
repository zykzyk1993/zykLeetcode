/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flattenHelper(root);    
    }
    TreeNode* flattenHelper(TreeNode* root){
        if(!root)return NULL;
        TreeNode* temp=root;
        TreeNode* rightTemp=root->right;
        if(root->left){
            temp=root->left;
            while(temp->left||temp->right){
                if(temp->right)
                    temp=temp->right;
                else
                    temp=temp->left;
            }
            root->right=flattenHelper(root->left);
        }
        
        if(rightTemp){
            temp->right=flattenHelper(rightTemp);
        }
        root->left=NULL;
        return root;
    }
};

class Solution {
public:
    TreeNode* pre=NULL;
    void flatten(TreeNode* root) {
        if(!root)return;
        flatten(root->right);
        flatten(root->left);
        root->right=pre;
        root->left=NULL;
        pre=root;
    }
};
