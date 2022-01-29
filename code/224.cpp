/*
 * 224. 基本计算器
 * 题意：计算由加减括号组成的字符串的计算结果
 * 难度：困难
 * 分类：栈
 * 算法：用sign保存当前符号，用st.top保存由于括号造成的符号，然后再得到最终的符号，将每个数字乘以最终的符号计算和
 */
class Solution {
public:
    int calculate(string s) {
        int res = 0, cur_num = 0, sign = 1;
        stack<int> st;
        st.push(1);
        for(int i = 0; i < s.size(); i ++) {
            if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if(s[i] == '(') {
                st.push(sign * st.top());
                sign = 1;
            }
            else if(s[i] == ')') {
                st.pop();
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                int cur_num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    cur_num = cur_num * 10 + (s[i] - '0');
                    i++;
                }
                res += sign * st.top() * cur_num;
                i--;
            }
            else {
                continue;
            }
        }
        return res;
    }
};
