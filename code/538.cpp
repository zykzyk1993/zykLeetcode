class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return NULL;
        if(root->right)
            convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        if(root->left)
            convertBST(root->left);
        return root;
    }
};
