/*
 * 94. 二叉树中序遍历
 * 题意：非递归二叉树中序遍历
 * 难度：中等
 * 分类：树 栈
 * 算法：经典问题，注意压栈然后每次一直走到最左
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(!root)return ans;
        s.push(root);
        while(root->left){
            root=root->left;
            s.push(root);
        }
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->right){
                temp=temp->right;
                s.push(temp);
                while(temp->left){
                    temp=temp->left;
                    s.push(temp);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode *p = root;
        while(!s.empty() || p){
            if(p) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                ans.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
