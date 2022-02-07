 /*
 * 114. 二叉树展开为链表
 * 将二叉树按照前序遍历展开为链表
 * 难度：中等
 * 分类：树 链表
 * 算法：按照模拟写法，先记录右子节点，flat左子树接到右子树上面，然后将右子树flat后接到最后一个节点上
 *      优雅写法，递归后序遍历，先右后左，用pre记录已展开好的第一个节点，然后从下往上来做
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flattenHelper(root);    
    }
    TreeNode* flattenHelper(TreeNode* root){
        if(!root)return NULL;
        TreeNode* temp=root;
        TreeNode* rightTemp=root->right;
        if(root->left){
            temp=root->left;
            while(temp->left||temp->right){
                if(temp->right)
                    temp=temp->right;
                else
                    temp=temp->left;
            }
            root->right=flattenHelper(root->left);
        }
        
        if(rightTemp){
            temp->right=flattenHelper(rightTemp);
        }
        root->left=NULL;
        return root;
    }
};

class Solution {
public:
    TreeNode* pre=NULL;
    void flatten(TreeNode* root) {
        if(!root)return;
        flatten(root->right);
        flatten(root->left);
        root->right=pre;
        root->left=NULL;
        pre=root;
    }
};
