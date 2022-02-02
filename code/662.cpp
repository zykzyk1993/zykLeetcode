/*
 * 662. 二叉树最大宽度
 * 题意：求二叉树最宽的一层，从最左到最右节点的间隔，中间可以有空节点
 * 难度：中等
 * 分类：树
 * 算法：层序遍历，但队列中需要保存序号
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        queue<pair<unsigned long long, TreeNode*>> q;
        q.push(make_pair(1, root));
        unsigned long long res = 1;
        while(!q.empty()) {
            int n = q.size();
            unsigned long long left = -1;
            for(int i = 0; i < n; i ++) {
                unsigned long long num = q.front().first;
                TreeNode * t = q.front().second;
                q.pop();
                if(left == -1) {
                    left = num;
                }
                else {
                    res = max(res, num - left + 1);
                }
                if(t->left) {
                    q.push(make_pair(num * 2, t->left));
                }
                if(t->right) {
                    q.push(make_pair(num * 2 + 1, t->right));
                }
            }
        }
        return res;
    }
};
