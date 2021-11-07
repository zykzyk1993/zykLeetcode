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

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
