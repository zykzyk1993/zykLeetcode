 /*
 * 155. 最小栈
 * 在栈的基础上实现查询栈中最小元素的功能
 * 难度：简单
 * 分类：栈
 * 算法：额外开辟辅助栈即可，最小栈栈顶保存栈中最小元素，有判断性操作
 */
class MinStack {
public:
    stack<int> s,minS;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(minS.empty()||minS.top()>=x)
            minS.push(x);
    }
    
    void pop() {
        int x=s.top();
        s.pop();
        if(minS.top()==x)
            minS.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
