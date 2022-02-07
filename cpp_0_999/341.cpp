/*
 * 341. 扁平化嵌套列表迭代器
 * 题意：给定数据结构，列表每个元素可能也是一个列表，实现next和hasnext的api
 * 难度：中等
 * 分类：树 dfs
 * 算法：相当于多叉树深度优先遍历，构造函数中，采用递归的方式dfs到每一个叶子结点，从而展平为一维数组
 */
 
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> data;
    int p = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        data = helper(nestedList);
    }

    vector<int> helper(vector<NestedInteger> &nestedList){
        vector<int> res;
        for(auto &nested:nestedList){
            if(nested.isInteger()){
                res.push_back(nested.getInteger());
            }
            else{
                vector<int> sub = helper(nested.getList());
                res.insert(res.end(), sub.begin(), sub.end());
            }
        }
        return res;
    }
    
    int next() {
        return data[p++];
    }
    
    bool hasNext() {
        return p < data.size();
    }
};

class NestedIterator {
private:
    vector<int> vals;
    vector<int>::iterator cur;

    void dfs(const vector<NestedInteger> &nestedList) {
        for (auto &nest : nestedList) {
            if (nest.isInteger()) {
                vals.push_back(nest.getInteger());
            } else {
                dfs(nest.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        cur = vals.begin();
    }

    int next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != vals.end();
    }
};
