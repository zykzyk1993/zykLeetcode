/*
 * 318. 最大单词长度乘积
 * 题意：求不含公共字母的两个单词的长度最大乘积
 * 难度：中等
 * 分类：位运算
 * 算法：先用数字记录每个单词的字母情况，然后用位运算直接得出两个单词是否有公共字母
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0, n = words.size();
        if(n == 0) return 0;
        vector<int> word_bit(n, 0);
        for(int i = 0; i < n; i++){
            for(auto &c:words[i]){
                word_bit[i] = word_bit[i] | (1<<(c-'a'));
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j ++){
                if((word_bit[i] & word_bit[j]) == 0){
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return ans;
    }
};
