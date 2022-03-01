/*
 * 199. 二叉树的右视图
 * 题意：求从右往左看，能看到的所有节点，从上到下
 * 难度：中等
 * 分类：二叉树
 * 算法：层序遍历，每次取最右的节点
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode * t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
                if(n == 0) {
                    ans.push_back(t->val);
                }
            }
        }
        return ans;
    }
};
