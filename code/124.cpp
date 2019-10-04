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
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        if(root->left){
            ans=max(ans,maxPathSum(root->left));
        }
        if(root->right){
            ans=max(ans,maxPathSum(root->right));
        }
        ans=max(ans,maxPath(root->left)+maxPath(root->right)+root->val);
        return ans;
    }
    int maxPath(TreeNode* root){
        if(!root)return 0;
        int ans=0;
        ans=max(ans,root->val+maxPath(root->left));
        ans=max(ans,root->val+maxPath(root->right));
        return ans;
    }
};

//正确dfs解法
class Solution {
public:
    int result=0;
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        result=root->val;
        dfs(root);
        return result;
    }
    int dfs(TreeNode* root){
        if(!root)return 0;
        int leftGain=max(dfs(root->left),0);
        int rightGain=max(dfs(root->right),0);
        result=max(result,root->val+leftGain+rightGain);
        return root->val+max(0,max(leftGain,rightGain));
    }
};
