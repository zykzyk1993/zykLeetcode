/*
 * 76. 最小覆盖子串
 * 原字符串中覆盖子串所有字符的最短串
 * 难度：困难
 * 分类：字符串 滑动窗口 双指针
 * 算法：用hashmap记录当前窗口和子串要求的字符数量，时刻右移左移并更新
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_cnt;
        for(char c:t)t_cnt[c]++;
        unordered_map<char,int> cnt;
        int t_size=t_cnt.size();
        int satisfy=0;
        int l=0,r=0,minLen=s.size()+1,minStart=0;
        while(r<s.size()){
            if(t_cnt[s[r]]>0){
                cnt[s[r]]++;
                if(cnt[s[r]]==t_cnt[s[r]])satisfy++;
            }
            while(satisfy==t_size){
                if(minLen>(r-l+1)){
                    minLen=r-l+1;
                    minStart=l;
                }
                if(t_cnt[s[l]]>0){
                    cnt[s[l]]--;
                    if(cnt[s[l]]<t_cnt[s[l]])satisfy--;
                }
                l++;
            }
            r++;
        }
        if(minLen==s.size()+1)return "";
        return s.substr(minStart,minLen);
    }
};

//代码优化
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128,0);
        for(char c:t)cnt[c]++;
        int left=0,minLeft=-1,minLen=INT_MAX,satisfy=0;
        for(int i=0;i<s.size();i++){
            if(--cnt[s[i]]>=0)++satisfy;
            while(satisfy==t.size()){
                if(i-left+1<minLen){
                    minLen=i-left+1;
                    minLeft=left;
                }
                if(++cnt[s[left]]>0)--satisfy;
                left++;
            }
        }
        return minLeft==-1?"":s.substr(minLeft,minLen);
    }
};
