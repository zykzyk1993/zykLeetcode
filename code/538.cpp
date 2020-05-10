  
/*
 * 538. 把二叉搜索树转换为累加树
 * 转换成每个节点的值是原来的节点值加上所有大于它的节点值之和的树
 * 难度：简单
 * 分类：二叉树
 * 算法：递归，中序遍历从右往左，然后记录全局变量sum
 */
class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return NULL;
        if(root->right)
            convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        if(root->left)
            convertBST(root->left);
        return root;
    }
};
