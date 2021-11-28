/*
 * 394. 字符串解码
 * 解码k[encoded_string]编码的字符串
 * 难度：中等
 * 分类：栈
 * 算法：使用两个栈分别保存数字和字符，注意压栈时机，每次压入当前数字和之前的字符
 */
class Solution {
public:
    string decodeString(string s) {
        stack<string> ss;
        stack<int> si;
        int curNum=0;
        string curString="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){ // 左括号 则压入括号前的数字 和 括号前的字符(可能为空)
                si.push(curNum);
                ss.push(curString);
                curNum=0;
                curString="";
            }else if(s[i]==']'){ // 右括号 弹出本组字符串前的数字，和括号前上一级的字符，数字乘上本级字符加入上一级字符后面
                int cnt=si.top();
                si.pop();
                string temp=ss.top();
                ss.pop();
                for(int j=0;j<cnt;j++){
                    temp+=curString;
                }
                curString=temp;
            }else if(s[i]>='0'&&s[i]<='9'){ //其他字符直接更新
                curNum=curNum*10+(s[i]-'0');
            }else{
                curString+=s[i];
            }
        }
        return curString;
    }
};
