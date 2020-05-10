/*
 * 617. 合并二叉树
 * 两棵二叉树叠加覆盖
 * 难度：简单
 * 分类：二叉树
 * 算法：递归，先判空，然后累加返回
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1&&!t2)return NULL;
        if(!t1)return t2;
        if(!t2)return t1;
        t1->val+=t2->val;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        return t1;
    }
};
