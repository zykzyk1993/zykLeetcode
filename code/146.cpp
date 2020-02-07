 /*
 * 146. LRU缓存机制
 * 实现指定大小LRU缓存的存取操作
 * 难度：中等
 * 分类：哈希 链表
 * 算法：使用队列来保存键值以及访问次序，然后使用键和迭代器来保存链表对应位置，每次访问，先删除队列对应位置再插入队头
 */
class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int mCapacity,count;
    list<pair<int,int>> queue;
    LRUCache(int capacity) {
        mCapacity=capacity;
        count=0;
    }
    
    int get(int key) {
        int res = -1;
        auto p = m.find(key);
        if (p != m.end()) {
            res = p->second->second;
            queue.erase(p->second);
            queue.push_front(make_pair(key, res));
            p->second = queue.begin();
        }
        return res;
    }
    
    void put(int key, int value) {
        auto p = m.find(key);
        if (p != m.end()) {
            queue.erase(p->second);
        }
        else if (count == mCapacity) {
            int delkey = queue.back().first;
            queue.pop_back();
            m.erase(delkey);
        }
        else {
            ++count;
        }
        queue.push_front(make_pair(key, value));
        m[key] = queue.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
