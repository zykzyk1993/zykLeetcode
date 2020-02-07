 /*
 * 105. 从前序与中序遍历序列构造二叉树
 * 如题
 * 难度：中等
 * 分类：树
 * 算法：辅助函数，记录节点，找到根节点在中序中的位置，然后递归左右
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return buildTreeHelper(preorder,inorder,0,n-1,0,n-1);
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int start1, int end1, int start2, int end2){
        if(start1>end1)return NULL;
        int rootVal=preorder[start1];
        TreeNode* root=new TreeNode(rootVal);
        int i=start2;
        while(i<end2&&inorder[i]!=preorder[start1])i++;
        int leftNodeNum=i-start2;
        root->left=buildTreeHelper(preorder,inorder,start1+1,start1+leftNodeNum,start2,i-1);
        root->right=buildTreeHelper(preorder,inorder,start1+leftNodeNum+1,end1,i+1,end2);
        return root;
    }
};
