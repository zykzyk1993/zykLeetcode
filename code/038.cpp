/*
 * 38. 外观数列
 * 题意：每一项是对前一项的描述，字符个数+字符
 * 难度：中等
 * 分类：字符串 模拟
 * 算法：逐步迭代，模拟
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)return "1";
        string res = "";
        string last_res = countAndSay(n-1);
        int cur_cnt = 1, m=last_res.size();
        for(int i = 1; i < m; i++){
            if(i > 0 && last_res[i] == last_res[i-1]){
                cur_cnt ++;
            }
            else{
                res.push_back(cur_cnt+'0');
                res.push_back(last_res[i-1]);
                cur_cnt=1;
            }
        }
        res.push_back(cur_cnt+'0');
        res.push_back(last_res[m-1]);
        return res;
    }
};
