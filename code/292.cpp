/*
 * 292. Nim 游戏
 * 题意：轮流拿石头，每次拿1～3个，求先手能否获胜
 * 难度：简单
 * 分类：数学
 * 算法：如果石头数量整除4则后手获胜，否则先手获胜
 */
class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};
