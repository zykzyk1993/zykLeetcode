/*
 * 380. O(1) 时间插入、删除和获取随机元素
 * 题意：设计如上数据结构
 * 难度：中等
 * 分类：哈希表 动态数组
 * 算法：用哈希表记录数组中对应元素的索引，删除时，将最后一个元素替换上来
 */
class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> m;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(m.count(val)){
            return false;
        }
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)){
            return false;
        }
        if(v.size() == 1){
            v.clear();
        }else{
            int idx = m[val];
            v[idx] = v[v.size() - 1];
            m[v[idx]] = idx;
            v.pop_back();
        }
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % (v.size());
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
