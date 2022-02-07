/*
 * 752. 打开转盘锁
 * 题意：返回从0000开始到打开转盘锁的最少操作次数，途中不能转入deadends，如果无法完成则返回-1
 * 难度：中等
 * 分类：bfs
 * 算法：把deadends先加入visited，然后bfs即可，注意判断0000如果是deadend则直接返回-1
 */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(), deadends.end());
        if(s.count("0000")){
            return -1;
        }
        int step = 0;
        queue<string> q;
        q.push("0000");
        s.insert("0000");
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                string cur = q.front();
                q.pop();
                if (cur == target) {
                    return step;
                }
                for (int i = 0; i < 4; i ++) {
                    string next1 = cur;
                    next1[i] = (next1[i] == '9')?'0':(next1[i] + 1);
                    if(!s.count(next1)) {
                        q.push(next1);
                        s.insert(next1);
                    }
                    string next2 = cur;
                    next2[i] = (next2[i] == '0')?'9':(next2[i] - 1);
                    if(!s.count(next2)) {
                        q.push(next2);
                        s.insert(next2);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
