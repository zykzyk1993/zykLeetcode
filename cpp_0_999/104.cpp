 /*
 * 104. 二叉树的最大深度
 * 判断整棵二叉树的最大深度
 * 难度：简单
 * 分类：树
 * 算法：递归判断，左右最大加1
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
