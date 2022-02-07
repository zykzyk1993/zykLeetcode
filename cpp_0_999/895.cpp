/*
 * 895. 最大频率栈
 * 题意：模拟一个栈，push正常，pop时弹出频率最高的，最近进栈的元素
 * 难度：困难
 * 分类：栈 哈希表
 * 算法：保存 元素-频率 频率-栈 两个哈希表 栈中表示该频率下的所有元素
 * 进栈时 更新频率，可能新建频率栈并更新max_freq，然后在该频率的栈中插入该元素
 * 出栈时 找到最大频率的栈，更新频率，频率栈中弹出元素，最大频率对应的栈更新后为空则更新max_freq
 */
class FreqStack {
public:
    unordered_map<int, int> key2freq;
    unordered_map<int, stack<int>> freq2stack;
    int max_freq = 0;
    FreqStack() {

    }
    
    void push(int val) {
        if(key2freq.count(val) == 0){
            key2freq[val] = 1;
        }else{
            key2freq[val] ++;
        }
        int freq = key2freq[val];
        if(freq2stack.count(freq) == 0){
            freq2stack[freq] = stack<int>();
            max_freq = max(max_freq, freq);
        }
        freq2stack[freq].push(val);
    }
    
    int pop() {
        int res = freq2stack[max_freq].top();
        if(key2freq[res] == 1){
            key2freq.erase(res);
        }else{
            key2freq[res]--;
        }
        freq2stack[max_freq].pop();
        if(freq2stack[max_freq].empty()){
            freq2stack.erase(max_freq);
            max_freq--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
