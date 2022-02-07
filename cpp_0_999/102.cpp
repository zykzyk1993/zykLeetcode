 /*
 * 102. 二叉树的层次遍历
 * 普通层序遍历
 * 难度：中等
 * 分类：树
 * 算法：队列，注意队列写法
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curLayer;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                curLayer.push_back(temp->val);
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            ans.push_back(curLayer);
            curLayer.clear();
        } 
        return ans;
    }
};
