/*
 * 99. 恢复二叉搜索树
 * 题意：二叉搜索树中有两个结点被调换了，将其恢复出来
 * 难度：中等
 * 分类：树
 * 算法：辅助函数，记录前驱结点的中序遍历，判断两个错位结点是否相邻共两种情况
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
    void inOrder(TreeNode *root, TreeNode *&pre, TreeNode *&t1, TreeNode *&t2){
        if(!root)
            return;
        if(root->left){
            inOrder(root->left, pre, t1, t2);
        }
        if(pre && pre->val > root->val){
            if(!t1){
                t1 = pre;
                t2 = root;
            }else{
                t2 = root;
            }
        }
        pre = root;
        if(root->right){
            inOrder(root->right, pre, t1, t2);
        }
    }
    void recoverTree(TreeNode* root) {
        TreeNode *pre = NULL, *t1 = NULL, *t2 = NULL;
        inOrder(root, pre, t1, t2);
        if(t1 && t2){
            int temp = t1->val;
            t1->val = t2->val;
            t2->val = temp;
        }
    }
};
