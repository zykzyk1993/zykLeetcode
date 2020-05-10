/*
 * 621. 任务调度器
 * 任务调度最小时间，两个相同种类的任务之间必须有长度为 n 的冷却时间
 * 难度：中等
 * 分类：贪心 数组
 * 算法：设计方法，要么可以使用l填满，否则最后一个需要maxCnt个最大的字符+1
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        int l=tasks.size(),maxCnt=0;
        for(auto c:tasks){
            cnt[c-'A']++;
            maxCnt=max(maxCnt,cnt[c-'A']);
        }
        int maxCntChar=0;
        for(int i=0;i<26;i++){
            if(cnt[i]==maxCnt)maxCntChar++;
        }
        return max((maxCnt-1)*(n+1)+maxCntChar,l);
    }
};
