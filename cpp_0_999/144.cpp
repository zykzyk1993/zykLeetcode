/*
 * 144. 二叉树的前序遍历
 * 题意：
 * 难度：简单
 * 分类：树
 * 算法：非递归用栈，先走到最左，然后退栈，向右一步，进栈时操作
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
    void preorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || !s.empty()){
            if(p){
                res.push_back(p->val);
                s.push(p);
                p = p->left;
            }else{
                p = s.top()->right;
                s.pop();
            }
        }
        return res;
    }
};
