/*
 * 236. 二叉树的最近公共祖先
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先
 * 难度：中等
 * 分类：树
 * 算法：采用注释的递归方法更加简洁，向上标记传递可能的结果
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q)return root;//标记叶子节点或者是直接找到的节点
        TreeNode* left=lowestCommonAncestor(root->left,p,q);//包含了是否找到节点以及节点祖先的信息
        TreeNode* right=lowestCommonAncestor(root->right,p,q);//包含了是否找到节点以及节点祖先的信息
        if(left&&right)return root;//如果左右都有，则一定为当前根节点，再次向上传递
        return left == NULL ? right : left;//该值可能为空或者
        //递归传值的方法
    }
};
