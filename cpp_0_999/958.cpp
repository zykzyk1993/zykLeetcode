/*
 * 958. 二叉树的完全性检验
 * 题意：判断是否为完全二叉树
 * 难度：中等
 * 分类：树
 * 算法：层序遍历(空节点也入队)，空节点后还有节点，则不是完全二叉树
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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            TreeNode * t = q.front();
            q.pop();
            if (t == nullptr) {
                flag = true;
                continue;
            }
            if (flag) {
                return false;
            }
            q.push(t->left);
            q.push(t->right);
        }
        return true;
    }
};
