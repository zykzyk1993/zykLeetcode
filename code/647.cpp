/*
 * 647. 回文子串
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 难度：中等
 * 分类：dp 字符串
 * 算法：经典回文子串dp算法，每次记得记录更新计数结果即可
 */
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),res=n;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(i<n-1&&s[i]==s[i+1]){
                dp[i][i+1]=true;
                res++;
            }
        }
        for(int len=2;len<n;len++){
            for(int start=0;start<n-len;start++){
                int end=start+len;
                if(dp[start+1][end-1]&&s[start]==s[end]){
                    dp[start][end]=true;
                    res++;
                }
            }
        }
        return res;
    }
};


//Mancher算法
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }
};
