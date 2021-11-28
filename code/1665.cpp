/*
 * 1665. 完成所有任务的最少初始能量
 * 题意：给定每个任务开始前所需能量，以及完成所消耗能量，可以任意顺序完成，求最小初始能量为多少
 * 难度：困难
 * 分类：数组 排序
 * 算法：关键在于理解自定义排序，要将开始所需能量和消耗能量差异最大的放在前面做，然后采用二分或者直接遍历即可
 */
class Solution {
public:
    bool C(const vector<vector<int>> &tasks, int start){
        for(auto &task:tasks){
            if(start < task[1]){
                return false;
            }
            start -= task[0];
        }
        return start >= 0;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int> &v1, const vector<int> &v2){
            int diff1 = v1[1] - v1[0], diff2 = v2[1] - v2[0];
            if(diff1 == diff2){
                return v1[1] > v2[1];
            }
            return diff1 > diff2;
        });
        int low = 0, high = 0, mid;
        for(auto &task:tasks){
            high += task[1];
        }
        while(low <= high){
            mid = low + (high - low)/2;
            if(C(tasks, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int> &v1, const vector<int> &v2){
            int diff1 = v1[1] - v1[0], diff2 = v2[1] - v2[0];
            return diff1 > diff2;
        });
        int res = 0, sum = 0; // sum存储能量之和
        for(auto &task:tasks){
            res = max(res, sum + task[1]); // 当前所需初始能量，可能为之前任务的sum+当前任务的开始所需能量[1]
            sum += task[0];
        }
        return res;
    }
};
