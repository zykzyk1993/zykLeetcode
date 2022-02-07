/*
 * 450. 删除二叉搜索树中的节点
 * 题意：找到二叉搜索树中等于给定值的节点，若有，则删除
 * 难度：中等
 * 分类：二叉树
 * 算法：分为查找和删除
 * 其中删除需要一个辅助函数，传入删除节点以及父节点
 * 若左右孩子有一个为空，则直接替换
 * 否则需要找到替换节点，然后将值替换上来后，递归删除该节点
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
    void helper(TreeNode *p, TreeNode* parent) {
        if(p->left == NULL || p->right == NULL) {
            TreeNode * next = p->left;
            if (p->right) {
                next = p->right;
            }
            if (parent->left == p) {
                parent->left = next;
            }
            else {
                parent->right = next;
            }
        }
        else {
            TreeNode * temp = p->left;
            TreeNode * temp_parent = p;
            while(temp->right) {
                temp_parent = temp;
                temp = temp->right;
            }
            p->val = temp->val;
            helper(temp, temp_parent);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *p = root, *parent = new TreeNode(-1);
        parent->left = root;
        TreeNode * ans = parent;
        while(p) {
            if(p->val == key) {
                break;
            }
            else if(p->val < key) {
                parent = p;
                p = p->right;
            }
            else {
                parent = p;
                p = p->left;
            }
        }
        if(!p) {
            return root;
        }
        helper(p, parent);
        return ans->left;
    }
};
