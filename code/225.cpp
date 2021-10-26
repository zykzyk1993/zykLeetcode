/*
 * 225. 用队列实现栈
 * 用队列操作实现普通栈的四个操作
 * 难度：简单
 * 分类：栈 队列
 * 算法：两个队列，q1用来正常保存元素，push，判空，取top都直接操作，pop的时候通过q2倒腾得到栈底元素
 */
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
