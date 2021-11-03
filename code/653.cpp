/*
 * 653. 两数之和 IV - 输入 BST
 * 题意：在二叉搜索树中找是否有和为target的两个数
 * 难度：简单
 * 分类：树
 * 算法：使用哈希表逐个二分找，或中序遍历存储后双指针找
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
    void inorder(TreeNode*root, vector<int> &nums){
        if(!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int sum =nums[l] + nums[r];
            if (sum == k){
                return true;
            }else if(sum < k){
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};
