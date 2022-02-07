/*
 * 150. 逆波兰表达式求值
 * 题意：逆波兰表达式：先存储两个操作数然后存储运算符号。还原结果
 * 难度：中等
 * 分类：栈
 * 算法：遇到符号取出两个数运算再压栈，否则直接压栈，栈内最终剩下答案
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string &t:tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                switch(t[0]){
                    case '+':
                        s.push(n1+n2);
                        break;
                    case '-':
                        s.push(n2-n1);
                        break;
                    case '*':
                        s.push(n1*n2);
                        break;
                    case '/':
                        s.push(n2/n1);
                        break;
                }
            }else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
