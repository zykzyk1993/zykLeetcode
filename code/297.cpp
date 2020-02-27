/**
使用先序递归序列来进行序列化与反序列化
to_string转化为string以逗号分隔；递归终点x->val==NULL

getline(s,str,',');每次读取','之前的字符串；递归终点str=="#"
**/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "#";
        else
            return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#")
            return NULL;
        stringstream s(data);
        return makedeserialize(s);
    }
    TreeNode* makedeserialize(stringstream&s){
        string str;
        getline(s,str,',');
        if(str=="#")
            return NULL;
        
        TreeNode* root=new TreeNode(stoi(str));
        root->left=makedeserialize(s);
        root->right=makedeserialize(s);
        
        return root;
    }
};
