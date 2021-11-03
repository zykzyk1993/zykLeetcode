/*
 * 889. 根据前序和后序遍历构造二叉树
 * 题意：
 * 难度：中等
 * 分类：树
 * 算法：结果不止一种，使用辅助函数，根据左右子结点切分递归
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
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int s1, int e1, int s2, int e2){
        if(s1 > e1){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[s1]);
        if(s1+1<=e1){
            int left_val = preorder[s1+1];
            int split = s2;
            while(split<=e2 && postorder[split]!=left_val){
                split++;
            }
            int left_num = split-s2+1;
            root->left = helper(preorder, postorder, s1+1, s1+left_num, s2, split);
            root->right = helper(preorder, postorder, s1+left_num+1, e1, split+1, e2-1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return helper(preorder, postorder, 0, n-1, 0, n-1);
    }
};
