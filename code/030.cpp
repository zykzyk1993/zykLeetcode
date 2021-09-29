/*
* 30. 串联所有单词的子串
* 题意：给定一个字符串和长度相同的单词 words 。找出s中恰好可以由words中所有单词串联形成的子串的起始位置
* 难度：困难
* 分类：字符串 滑窗
* 算法：滑动窗口，注意窗口条件是必须每个字符恰好满足
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int ss = s.size(), w = words.size(), n = words[0].size();
        unordered_map<string, int> word_cnt;
        for(auto &word:words){
            word_cnt[word]++;
        }
        unordered_map<string, int> need_cnt = word_cnt;
        for (int i = 0; i < n; i++) {
            int start = i, end=i;
            // 新一轮搜索
            need_cnt = word_cnt;
            int satisfy = 0;
            while(start <= ss - w*n && end <= ss - n) {
                string cur_word = s.substr(end, n);
                // 不在字典内，重置
                if(word_cnt.count(cur_word) == 0) {
                    start = end + n;
                    end = end + n;
                    satisfy = 0;
                    need_cnt = word_cnt;
                    continue;
                }
                //在字典内，是所需要的字符
                if (need_cnt[cur_word] > 0) {
                    need_cnt[cur_word] --;
                    end += n; // 右移
                    satisfy ++;
                }
                // 在字典内，但是多余字符
                else {
                    // 必须左移到多余的字符
                    while(s.substr(start, n) != cur_word) {
                        need_cnt[s.substr(start, n)] ++;
                        start +=n;
                        satisfy--;
                    }
                    // 两者一起右移
                    start += n;
                    end += n;
                }
                // 满足条件
                if (satisfy == w) {
                    string prev_word = s.substr(start, n);
                    need_cnt[prev_word] ++;
                    res.push_back(start);
                    start += n;
                    satisfy --;
                }
            }
        }
        return res;
    }
};
