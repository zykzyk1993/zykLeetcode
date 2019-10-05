/*
 * 5. 最长回文子串
 * 题意：找出给定字符串中最长的回文串
 * 难度：中等
 * 分类：字符串，dp
 * 算法：从中间往两边扩展dp数组，初始状况有两种：长度为1和长度为2的
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }
};

//manacher算法
int maxLcsplength(string str) {
    //空字符串直接返回0
    if (str.length() == 0) {
        return 0;
    }
    //记录下manacher字符串的长度，方便后面使用
    int len = (int)(str.length() * 2 + 1);
    //开辟动态数组chaArr记录manacher化的字符串
    //开辟动态数组pArr记录每个位置的回文半径
    char *chaArr = new char[len];
    int* pArr = new int[len];
    int index = 0;
    for (int i = 0; i < len;i++) {
        chaArr[i] = (i & 1) == 0 ? '#' : str[index++];
    }
    //到此完成对原字符串的manacher化
    //R是最右回文边界，C是R对应的最左回文中心，maxn是记录的最大回文半径
    int R = -1;
    int C = -1;
    int maxn = 0;
    //开始从左到右遍历
    for (int i = 0; i < len; i++) {
        //第一步直接取得可能的最短的回文半径，当i>R时，最短的回文半径是1，反之，最短的回文半径可能是i对应的i'的回文半径或者i到R的距离
        pArr[i] = R > i ? min(R - i, pArr[2 * C - i]) : 1;
        //取最小值后开始从边界暴力匹配，匹配失败就直接退出
        while (i + pArr[i]<len && i - pArr[i]>-1) {
            if (chaArr[i + pArr[i]] == chaArr[i - pArr[i]]) {
                pArr[i]++;
            }
            else {
                break;
            }
        }
        //观察此时R和C是否能够更新
        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }
        //更新最大回文半径的值
        maxn = max(maxn, pArr[i]);
    }
    //记得清空动态数组哦
    delete[] chaArr;
    delete[] pArr;
    //这里解释一下为什么返回值是maxn-1，因为manacherstring的长度和原字符串不同，所以这里得到的最大回文半径其实是原字符串的最大回文子串长度加1，有兴趣的可以自己验证试试
    return maxn - 1;
}
