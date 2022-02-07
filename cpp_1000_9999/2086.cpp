/*
 * 2086. 从房屋收集雨水需要的最少水桶数
 * 题意：至少需要在房屋的两侧的空位放一个桶接雨水，最少需要放多少个，如果没法满足则返回-1
 * 难度：中等
 * 分类：数组 贪心
 * 算法：如果有就不放 否则尽可能放右侧，如果都满足不了再返回-1
 */
class Solution {
public:
    int minimumBuckets(string street) {
        int res = 0, n = street.size();
        if(n == 1){
            return street[0] == '.'?0:-1;
        }
        bool need = false;
        for(int i = 0; i < n; i++){
            if(street[i] == 'H'){
                if(i > 0 && street[i-1] == 'B'){
                    continue;
                }else if(i < n - 1 && street[i+1] == '.'){
                    street[i+1] = 'B';
                    res++;
                }else if(i > 0 && street[i-1] == '.'){
                    street[i-1] = 'B';
                    res++;
                }
                else{
                    return -1;
                }
            }
        }
        return res;
    }
};
