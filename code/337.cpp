class Solution {
public:
    vector<int> robHelper(TreeNode* root){
        if(!root)return {0,0};
        vector<int> robLeft = robHelper(root->left);
        vector<int> robRight = robHelper(root->right);
        vector<int> res;
        res.push_back(robLeft[1]+robRight[1]+root->val);
        res.push_back(max(robLeft[0],robLeft[1])+max(robRight[0],robRight[1]));
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> res = robHelper(root);
        return max(res[0],res[1]);
    }
};
