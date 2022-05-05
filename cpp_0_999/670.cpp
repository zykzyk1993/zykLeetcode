/*
 * 670. 最大交换
 * 题意：只多交换一次数字中的两位，求最大结果
 * 难度：中等
 * 分类：数学
 * 算法：找到0～9的最后一次出现的位置，然后从前往后遍历，如果有大于当前位的数可换，则直接换，然后返回
 */
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> last_idx(10, 0);
        string str = to_string(num);
        for(int i = 0; i < str.size(); i ++) {
            last_idx[str[i] - '0'] = i;
        }
        for(int i = 0; i < str.size(); i ++) {
            for (int j = 9; j > (str[i] - '0'); j --) {
                if (last_idx[j] > i) {
                    swap(str[i], str[last_idx[j]]);
                    return stoi(str);
                }
            }
        }
        return stoi(str);
    }
};
