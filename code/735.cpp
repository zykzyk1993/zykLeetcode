/*
 * 735. 行星碰撞
 * 题意：行星数列，正负代表移动方向，行星相互之间碰撞后小的或相等的消失，求最后留下的
 * 难度：中等
 * 分类：栈
 * 算法：考虑两个方向(留下的正行星和负行星)，正向遍历遇到正行星压栈，遇到负行星查看有多少需要被弹栈，最后就是留下的。反向遍历类似
 * 注意栈中保留索引，方便排序
 */
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        for(int i = 0; i < n; i ++) {
            if(asteroids[i] > 0) {
                s.push(i);
            }else{
                while(!s.empty()){
                    int st = asteroids[s.top()];
                    if(st < -asteroids[i]){
                        s.pop();
                    }else if(st == -asteroids[i]){
                        s.pop();
                        break;
                    }else{
                        break;
                    }
                }
            }
        }
        vector<int> res_idx;
        while(!s.empty()){
            res_idx.push_back(s.top());
            s.pop();
        }
        for(int i = n-1; i >= 0; i --) {
            if(asteroids[i] < 0) {
                s.push(i);
            }else{
                while(!s.empty()){
                    int st = asteroids[s.top()];
                    if(-st < asteroids[i]){
                        s.pop();
                    }else if(-st == asteroids[i]){
                        s.pop();
                        break;
                    }else{
                        break;
                    }
                }
            }
        }
        while(!s.empty()){
            res_idx.push_back(s.top());
            s.pop();
        }
        sort(res_idx.begin(), res_idx.end());
        vector<int> res;
        for(auto &i:res_idx){
            res.push_back(asteroids[i]);
        }
        return res;
    }
};
