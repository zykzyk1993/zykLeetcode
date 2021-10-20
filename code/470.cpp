/*
 * 470. 用 Rand7() 实现 Rand10()
 * 题意：用给定的rand7 api实现 rand10
 * 难度：中等
 * 分类：数学
 * 算法：使用两次rand7，构成49种可能，对于前40种取10的余数，丢弃后9种
 */
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true){
            int n1 = rand7() - 1, n2 = rand7() - 1;
            int n = n1 * 7 + n2;
            if(n < 40){
                return n % 10 + 1;
            }
        }
    }
};
