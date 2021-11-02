/*
 * 1110. 删点成林
 * 题意：将给定值的树节点删除，返回森林的所有根节点
 * 难度：中等
 * 分类：树
 * 算法：辅助函数，记录parent节点，删除节点可以改变对应指针，注意每一种情况
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
    void helper(TreeNode* root, TreeNode* parent, vector<TreeNode*> &res, unordered_set<int> &s){
        if(!root){
            return;
        }
        if(s.count(root->val)){ //根节点需要删除
            if(parent){ //如果有parent，则断开
                if(parent->left == root){
                    parent->left = NULL;
                }else{
                    parent->right = NULL;
                }
            }
            helper(root->left, NULL, res, s); //根节点被删除，parent为空
            helper(root->right, NULL, res, s);
        }else{ //不需要删除根节点
            if(!parent){ //有效根节点，加入res
                res.push_back(root);
            }
            helper(root->left, root, res, s); //parent为根节点
            helper(root->right, root, res, s);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        helper(root, NULL, res, s);
        return res;
    }
};
