/*
 * 637. 二叉树的层平均值
 * 题意：如上
 * 难度：简单
 * 分类：树
 * 算法：层序遍历
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            double sum = 0, n = q.size();
            for(int i = 0; i < n; i ++){
                TreeNode * t = q.front();
                q.pop();
                sum += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(sum / n);
        }
        return res;
    }
};
