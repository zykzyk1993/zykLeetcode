/*
 * 257. 二叉树的所有路径
 * 题意：将树中所有根结点到叶子结点的路径用字符串返回
 * 难度：简单
 * 分类：树 dfs
 * 算法：dfs，叶子条件为终止
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
    void dfs(vector<string> &ans, string cur, TreeNode* root){
        if(!root->left && !root->right){
            ans.push_back(cur);
        }
        if(root->left){
            dfs(ans, cur+"->"+to_string(root->left->val), root->left);
        }
        if(root->right){
            dfs(ans, cur+"->"+to_string(root->right->val), root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)
            return ans;
        dfs(ans, to_string(root->val), root);
        return ans;
    }
};
