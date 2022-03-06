/*
 * 297. 二叉树的序列化与反序列化
 * 题意：不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构
 * 难度：困难
 * 分类：树 字符串
 * 算法：按照先序遍历递归操作，注意字符串操作 stringstream
 */
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

// 2022
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "#";
        }
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string delimiter = ",";
        vector<string> datas;

        size_t pos = 0;
        while ((pos = data.find(delimiter)) != string::npos) {
            datas.push_back(data.substr(0, pos));
            data.erase(0, pos + delimiter.length());
        }
        if(data.size()){
            datas.push_back(data);
        }
        int idx = 0;
        return deserialize_helper(datas, idx);
    }

    TreeNode* deserialize_helper(vector<string> &data, int &idx) {
        if(data[idx] == "#"){
            idx ++;
            return NULL;
        }
        TreeNode * root = new TreeNode(stoi(data[idx]));
        idx++;
        root->left = deserialize_helper(data, idx);
        root->right = deserialize_helper(data, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
