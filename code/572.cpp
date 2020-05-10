/*
 * 572. 另一个树的子树
 * 一棵树t是否是另一棵树s的子树，子树表示结构完全一致
 * 难度：简单
 * 分类：二叉树
 * 算法：构造辅助函数判断是否为相同的树，然后递归判断子树
 */
class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t){
        if(s==NULL&&t==NULL)return true;
        if((s==NULL&&t!=NULL)||(s!=NULL&&t==NULL)||(s->val!=t->val))
            return false;
        return isSameTree(s->left,t->left)&&isSameTree(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL&&t==NULL)return true;
        if((s==NULL&&t!=NULL)||(s!=NULL&&t==NULL))
            return false;
        if(isSameTree(s,t))
            return true;
        return isSubtree(s->left,t)||isSubtree(s->right,t);
    }
};
