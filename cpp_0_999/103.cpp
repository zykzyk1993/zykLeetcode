 /*
 * 103. 二叉树的锯齿形层次遍历
 * 普通层序遍历
 * 难度：中等
 * 分类：树
 * 算法：注意计算层数
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curLayer;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        int layer = 0;
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
            if (layer % 2) {
              reverse(curLayer.begin(), curLayer.end());
            }
            ans.push_back(curLayer);
            curLayer.clear();
            layer ++;
        } 
        return ans;
    }
};
