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
