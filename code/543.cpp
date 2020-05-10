/*
 * 543. 二叉树的直径
 * 节点之间路径长度的最大值
 * 难度：简单
 * 分类：二叉树
 * 算法：计算以每个节点为根节点的最大深度，同时根据其左右深度的值之和更新ans
 */
class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) return 0; // 访问到空节点了，返回0
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};
