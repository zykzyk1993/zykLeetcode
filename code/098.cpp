//递归判断，保留上下界
class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, TreeNode* leftNode, TreeNode* rightNode){
        if(!root)return true;
        if(leftNode&&leftNode->val>=root->val)return false;
        if(rightNode&&rightNode->val<=root->val)return false;
        if(!isValidBSTHelper(root->left,leftNode,root))return false;
        if(!isValidBSTHelper(root->right,root,rightNode))return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, NULL, NULL);
    }
};

//非递归中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        int pre=0;
        bool flag=false;
        if(!root)return true;
        s.push(root);
        while(root->left){
            root=root->left;
            s.push(root);
        }
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            if(flag&&pre>=temp->val)return false;
            pre=temp->val;
            flag=true;
            if(temp->right){
                temp=temp->right;
                s.push(temp);
                while(temp->left){
                    temp=temp->left;
                    s.push(temp);
                }
            }
        }
        return true;
    }
