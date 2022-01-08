/*
 * 230. 二叉搜索树中第K小的元素
 * 题意：如题
 * 难度：中等
 * 分类：二叉树
 * 算法：非递归中序遍历
 */

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int res = 0;
        TreeNode *p = root;
        while(!s.empty() || p) {
            if(p) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
                k--;
                if (k == 0) {
                    res = p->val;
                    break;
                }
                p = p->right;
            }
        }
        return res;
    }
};
