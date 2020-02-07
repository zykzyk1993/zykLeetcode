 /*
 * 101. 对称二叉树
 * 验证两棵二叉树是否相互对称
 * 难度：简单
 * 分类：树
 * 算法：1.通过辅助函数递归判断 2.通过中序层序遍历也可以做
 */
//递归判断镜像
class Solution {
public:
    bool isSymmetricHelper(TreeNode* root1, TreeNode* root2){
        if(root1==NULL&&root2==NULL)return true;
        else if(root1!=NULL&&root2!=NULL&&(root1->val==root2->val))
            return isSymmetricHelper(root1->left,root2->right)&&isSymmetricHelper(root1->right,root2->left);
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return isSymmetricHelper(root->left,root->right);
    }
};
//非递归中序，层序遍历都可以做
