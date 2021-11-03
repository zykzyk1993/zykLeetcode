/*
 * 513. 找树左下角的值
 * 题意：找到二叉树最底层最左侧的值
 * 难度：中等
 * 分类：树
 * 算法：层序遍历，设置一个new_level记录新一层是否有结点
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()){
            int n = q.size();
            bool new_level = true;
            for(int i = 0; i < n; i ++){
                TreeNode * t = q.front();
                q.pop();
                if(t->left){
                    if(new_level){
                        ans = t->left->val;
                        new_level = false;
                    }
                    q.push(t->left);
                }
                if(t->right){
                    if(new_level){
                        ans = t->right->val;
                        new_level = false;
                    }
                    q.push(t->right);
                }
            }
        }
        return ans;
    }
};
