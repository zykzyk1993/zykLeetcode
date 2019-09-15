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
