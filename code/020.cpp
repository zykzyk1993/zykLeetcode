 /*
 * 20. 有效的括号
 * 题意：给定括号序列判断是否有效
 * 难度：简单
 * 分类：栈
 * 算法：模拟入栈出栈，判断栈顶，结束时判断栈空，基本操作
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            switch(c){
                case '(':
                case '[':
                case '{':
                    st.push(c);
                    break;
                case ')':
                    if(st.empty()||st.top()!='('){
                        return false;
                    }
                    st.pop();
                    break;
                case ']':
                    if(st.empty()||st.top()!='['){
                        return false;
                    }
                    st.pop();
                    break;
                case '}':
                    if(st.empty()||st.top()!='{'){
                        return false;
                    }
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};
