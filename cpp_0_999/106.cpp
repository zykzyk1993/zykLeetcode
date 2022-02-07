/*
 * 106. 从中序与后序遍历序列构造二叉树
 * 题意：
 * 难度：中等
 * 分类：树
 * 算法：辅助函数，从中序遍历序列中找到根结点，拆分为左右分支，递归
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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int s1, int e1, int s2, int e2){
        if(s1 > e1){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[e1]);
        int split = s2;
        while(split <= e2 && inorder[split] != postorder[e1]) split++;
        int left_num = split - s2;
        root->left = helper(postorder, inorder, s1, s1+left_num-1, s2, split-1);
        root->right = helper(postorder, inorder, s1+left_num, e1-1, split+1, e2);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(postorder, inorder, 0, n-1, 0, n-1);
    }
};
