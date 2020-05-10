/*
 * 437. 路径总和 III
 * 二叉树中，找出路径和等于给定数值的路径总数。
 * 难度：简单
 * 分类：二叉树
 * 算法：分为使用root和未使用root的情况来处理，使用了root，则接下来都要使用root
 */
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
