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
