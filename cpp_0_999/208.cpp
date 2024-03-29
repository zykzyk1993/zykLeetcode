/*
 * 208. 实现Trie树
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 难度：中等
 * 分类：树 Trie树
 * 算法：注意Trie树写法，采用26指针，并包含isLast标记
 */
class Node {
public:
    bool isLast;
    Node* next[26];
    Node(){
        isLast = false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
};
class Trie {
public:
    Node * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        Node* p = root;
        for(int i=0;i<n;i++){
            if(p->next[word[i]-'a']==NULL){
                p->next[word[i]-'a'] = new Node();
            }
            p=p->next[word[i]-'a'];
        }
        p->isLast=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        Node* p = root;
        for(int i=0;i<n;i++){
            if(p->next[word[i]-'a']==NULL)
                return false;
            p=p->next[word[i]-'a'];
        }
        return p->isLast;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* p = root;
        for(int i=0;i<n;i++){
            if(p->next[prefix[i]-'a']==NULL)
                return false;
            p=p->next[prefix[i]-'a'];
        }
        return true;
    }
};
