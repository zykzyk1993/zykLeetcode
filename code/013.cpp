/*
 * 13. 罗马数字转整数
 * 题意：按照罗马数字规则转整数
 * 难度：简单
 * 分类：数学 字符串
 * 算法：012反向
 */
class Solution {
public:
    int romanToInt(string s) {
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int res = 0, cur_idx = 0;
        for(int i=0; i<13;i++){
            while(s.substr(cur_idx, reps[i].size()) == reps[i]) {
                res += values[i];
                cur_idx += reps[i].size();
            }
        }
        return res;
    }
};
