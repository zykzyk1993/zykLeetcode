/*
 * 679. 24 点游戏
 * 题意：判断4个数字用三个运算符连接后是否可以形成24点，除法取整
 * 难度：困难
 * 分类：dfs
 * 算法：采用erase begin和push_back的方式轮换dfs，每次取出两个数放回一个数
 */
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> l;
        for(int i = 0;i < cards.size();i++){
            l.push_back((double)cards[i]);
        }
        return helper(l);
    }
    bool helper(vector<double>& list){
        if(list.size() == 1) return abs(list[0] - 24) < 1e-6;
        for(auto num : list){
            double a = list[0];
            list.erase(list.begin());
            for(auto mun : list){
                double b = list[0];
                list.erase(list.begin());
                for(auto n : {a+b, a-b, a*b}){
                    list.push_back(n);
                    if(helper(list)) return true;
                    list.pop_back();
                }
                if(b!= 0){
                    list.push_back(a/b);
                    if(helper(list)) return true;
                    list.pop_back();
                }
                list.push_back(b);
            }
            list.push_back(a);
        }
        return false;
    }
};
