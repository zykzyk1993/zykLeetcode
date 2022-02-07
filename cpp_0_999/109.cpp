/*
 * 109. 有序链表转换二叉搜索树
 * 题意：将链表转化为平衡二叉树，其中序遍历按照链表顺序
 * 难度：中等
 * 分类：树
 * 算法：使用快慢指针折半，然后递归。第二种为高效解法，二分，中序遍历
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode *fast = head, *slow = head, *prev = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        if(prev){
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

//高效解法
class Solution {
public:
    int getLength(ListNode* head) {
        int ret = 0;
        for (; head != nullptr; ++ret, head = head->next);
        return ret;
    }

    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        return buildTree(head, 0, length - 1);
    }
};
