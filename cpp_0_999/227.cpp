/*
 * 227. 基本计算器 II
 * 题意：计算包含+-* /的字符串表达式
 * 难度：中等
 * 分类：字符串 栈
 * 算法：用栈按照加法方式保存，见注释，注意考虑空格
 * 双栈法
 */
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int num = 0, i = 0;
        // 放入第一个数
        while(i < s.size() && (isdigit(s[i])||s[i] == ' ')){
            if(s[i] == ' '){
                i++;
                continue;
            }
            num = num * 10 + (s[i++] - '0');
        }
        nums.push(num);
        int ans = 0;
        // 遇到运算符 找到下一个数字，如果+-直接推入原数或相反数，
        // */取栈顶运算后推入
        while(i < s.size()){
            if(s[i] == ' '){
                i++;
                continue;
            }
            int num = 0, prev_num = 0;
            char c = s[i++];
            while(i < s.size() && (isdigit(s[i])||s[i] == ' ')){
                if(s[i] == ' '){
                    i++;
                    continue;
                }
                num = num * 10 + (s[i++] - '0');
            }
            switch (c)
            {
            case '+':
                nums.push(num);
                break;
            case '-':
                nums.push(-num);
                break;
            case '*':
                prev_num = nums.top();
                nums.pop();
                nums.push(prev_num * num);
                break;
            case '/':
                prev_num = nums.top();
                nums.pop();
                nums.push(prev_num / num);
                break;
            }
        }
        //最后栈内所有元素相加即为得数
        while(!nums.empty()){
            ans += nums.top();
            nums.pop();
        }
        return ans;
    }
};

//双栈法，保存运算符和操作数，并定义优先级，只有前一个运算符优先级高于当前运算符优先级时才运算
class Solution {
public:
    unordered_map<char,int> oper_pri = {
            {'+',1},
            {'-',1},
            {'*',2},
            {'/',2},
            {'%',2},
            {'^',3}
    };
    stack<char> opers;
    stack<long long> nums;
    int calculate(string s) {
        nums.push(0);
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]==' ') continue;
            else if(s[i]=='(') {
                opers.push('(');
                if(s[i+1]=='-'){
                    i++;
                    nums.push(0);
                    opers.push('-');
                }
            }
            else if(s[i]==')'){
                while(opers.top()!='('){
                    cal();
                }
                opers.pop();
            }
            else if('0'<=s[i] && s[i]<='9'){
                int l = i;
                while(i+1<n && '0'<=s[i+1] && s[i+1]<='9')
                    i++;
                nums.push(stoll(s.substr(l,i-l+1)));
            }
            else{
                while(!opers.empty() && opers.top()!='(' && oper_pri[opers.top()] >= oper_pri[s[i]]){
                    cal();
                }
                opers.push(s[i]);
            }
        }
        while(!opers.empty() && opers.top()!='('){
            cal();
        }
        return nums.top();
    }
    void cal(){
        long long b = nums.top(); nums.pop();
        long long a = nums.top(); nums.pop();
        char oper = opers.top(); opers.pop();
        long long res;
        switch (oper) {
            case '+':   res = a + b; break;
            case '-':   res = a - b; break;
            case '*':   res = a * b; break;
            case '/':   res = a / b; break;
            case '%':   res = a % b; break;
            case '^':   res = pow(a,b); break;
        }
        nums.push(res);
    }
};

// 2022
class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
