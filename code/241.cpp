/*
 * 241. 为运算表达式设计优先级
 * 题意：给表达式增加括号，返回所有可能的结果
 * 难度：中等
 * 分类：分治
 * 算法：按照每一个符号递归拆分计算，如果没有运算符则返回单个数字
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        bool has_op = false;
        vector<int> res;
        for(int i = 0; i < expression.size(); i++){
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                has_op = true;
                vector<int> left_res = diffWaysToCompute(expression.substr(0, i));
                vector<int> right_res = diffWaysToCompute(expression.substr(i+1));
                for(auto &left:left_res){
                    for(auto &right:right_res){
                        if(c == '+'){
                            res.push_back(left+right);
                        }
                        else if(c == '-'){
                            res.push_back(left-right);
                        }
                        else if(c == '*'){
                            res.push_back(left*right);
                        }
                    }
                }
            }
        }
        if(!has_op){
            return {stoi(expression)};
        }else{
            return res;
        }
    }
};
