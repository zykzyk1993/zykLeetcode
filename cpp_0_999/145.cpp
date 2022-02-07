/*
 * 145. 二叉树的后序遍历
 * 题意：非递归二叉树后序遍历
 * 难度：中等
 * 分类：树 栈
 * 算法：要保存右节点是否访问过，没访问则访问，否则弹出本节点，可以用set或visited
 * 注意还有Morris遍历方法，只需要常数空间
 */
class Solution {
public:
    void postorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        unordered_set<TreeNode*> visited;
        while(p || !s.empty()){
            if(p){
                s.push(p);
                p = p->left;
            }else{
                TreeNode *t = s.top();
                if(visited.count(t)){
                    res.push_back(s.top()->val);
                    s.pop();
                }else{
                    p = t->right;
                    visited.insert(t);
                }
            }
        }
        return res;
    }
};
