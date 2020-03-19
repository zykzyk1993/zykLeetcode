class Solution {
public:
    int pathSumRoot(TreeNode* root, int sum) {
        int ans=0;
        if(!root)return 0;
        if(root->val==sum) ans++;
        ans+=pathSumRoot(root->left,sum-root->val);
        ans+=pathSumRoot(root->right,sum-root->val);
        return ans;
    }

    int pathSum(TreeNode* root, int sum) {
        int ans=0;
        if(!root)return 0;
        if(root->val==sum) ans++;
        ans+=pathSum(root->left,sum);
        ans+=pathSum(root->right,sum);
        ans+=pathSumRoot(root->left,sum-root->val);
        ans+=pathSumRoot(root->right,sum-root->val);
        return ans;
    }
};
