/*
 * 556. 下一个更大元素 III
 * 题意：给定数字，求排列组合后下一个更大的数字，没有则返回-1
 * 难度：中等
 * 分类：数学
 * 算法：本质上是找到一个升序的位置，然后找到恰好大于当前数字的作为调换位置，调换后将右侧数位都翻转
 */
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int m = digits.size();
        if (m < 2) {
            return -1;
        }
        reverse(digits.begin(), digits.end());
        int candidate_idx = -1;
        for (int j = m - 1; j > 0; j --) {
            if (digits[j] > digits[j - 1]) {
                candidate_idx = j - 1;
                break;
            }
        }
        if (candidate_idx == -1) {
            return -1;
        }
        int swap_idx = candidate_idx + 1;
        while(swap_idx < m - 1 && digits[swap_idx + 1] > digits[candidate_idx]) {
            swap_idx ++;
        }
        swap(digits[candidate_idx], digits[swap_idx]);
        long long res = 0;
        for (int i = 0; i <= candidate_idx; i ++) {
            res = res * 10 + digits[i];
        }
        for (int j = m - 1; j > candidate_idx; j --) {
            res = res * 10 + digits[j];
        }
        return res > INT_MAX ? -1 : res;
    }
};
