/*
 * 716. 最大栈
 * 题意：支持如下几个操作
 * 难度：简单
 * 分类：哈希表 链表
 * 算法：用哈希表 链表来实现，有序map保存下标
 */
class MaxStack {
    list<int> l;
    map<int, vector<list<int>::iterator>> m;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        l.push_front(x);
        m[x].push_back(l.begin());
    }
    
    int pop() {
        int v = l.front();
        m[v].pop_back();
        if(m[v].empty())
            m.erase(v);
        l.pop_front();
        return v;
    }
    
    int top() {
        return l.front();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int v = m.rbegin()->first;
        auto it = m[v].back();
        m[v].pop_back();
        if(m[v].empty())
            m.erase(v);
        l.erase(it);
        return v;
    }
};
