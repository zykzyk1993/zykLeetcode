/*
 * 235. 二叉搜索树的最近公共祖先
 * 题意：找到二叉搜索树中，两个结点的最近公共祖先
 * 难度：简单
 * 分类：树
 * 算法：根据两个结点的值与当前结点值的大小关系决定向左还是向右走
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }
};
