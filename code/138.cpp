/*
 * 138. 复制带随机指针的链表
 * 题意：链表中带有随机指针，复制一份完整的链表
 * 难度：中等
 * 分类：链表
 * 算法：先穿插的复制一个节点，接在原链表节点之后，这样方便找随机指针，然后拆除出来
 */
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return NULL;
        }
        Node* p = head;
        while(p) { // 复制链表
            Node *newNode = new Node(p->val);
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next;
        }
        p = head;
        while(p) { // 复制随机指针
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        // 拆分两个链表
        Node * dummy = new Node(-1);
        dummy->next = head->next;
        Node * q = dummy;
        p = head;
        while(p) {
            q->next = p->next;
            q = p->next;
            p->next = p->next->next;
            p = p->next;
        }
        return dummy->next;
    }
};
