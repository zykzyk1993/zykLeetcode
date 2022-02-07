/*
 * 912. 排序数组
 * 题意：实现各种排序算法
 * 难度：中等
 * 分类：排序
 * 算法：略
 */
// 快速排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int> &nums, int l, int r){
        if(l < r){
            int mid = parition(nums, l, r);
            quickSort(nums, l, mid - 1);
            quickSort(nums, mid + 1, r);
        }
    }
    int parition(vector<int> &nums, int l, int r){
        int idx = rand() % (r - l) + l;
        swap(nums[idx], nums[l]);
        int pivot = nums[l];
        while(l < r){
            while(l < r && nums[r] >= pivot) r--;
            if (l < r) nums[l] = nums[r];
            while(l < r && nums[l] <= pivot) l++;
            if (l < r) nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
};

// 堆排序
class Solution {
public:
    void adjustHeap(vector<int> &nums, int i) {
        int n = nums.size();
        int child_idx = i * 2 + 1;
        if (child_idx >= n) {
            return;
        }
        if (child_idx + 1 < n && nums[child_idx + 1] < nums[child_idx]) {
            child_idx ++;
        }
        if (nums[child_idx] < nums[i]) {
            swap(nums[child_idx], nums[i]);
            adjustHeap(nums, child_idx);
        }
    }
    void buildHeap(vector<int> &nums) {
        int n = nums.size();
        for(int i = n / 2; i >= 0; i --) {
            adjustHeap(nums, i);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res;
        buildHeap(nums);
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            res.push_back(nums[0]);
            nums[0] = nums.back();
            nums.pop_back();
            adjustHeap(nums, 0);
        }
        return res;
    }
};

// 归并排序
class Solution {
public:
    vector<int> res;
    void mergeSort(vector<int> &nums, int start, int end) {
        if(start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        int i = start, j = mid + 1, k = start;
        while(i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                res[k++] = nums[i++];
            }
            else {
                res[k++] = nums[j++];
            }
        }
        while(i <= mid) {
            res[k++] = nums[i++];
        }
        while(j <= end) {
            res[k++] = nums[j++];
        }
        for(int i = start; i <= end; i ++) {
            nums[i] = res[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        res = nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
