/*
 * 295. 数据流的中位数
 * 题意：两个操作，新增数据，获取中位数，希望O(1)获取中位数
 * 难度：困难
 * 分类：堆
 * 算法：维护大顶堆和小顶堆，分别存放小的半部分的和大的半部分数据，保持数量均衡，堆顶元素即为中位数
 */
class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(max_pq.empty()){
            max_pq.push(num);
            return;
        }
        int max_top = max_pq.top();
        if(max_top > num){
            max_pq.push(num);
        }else{
            min_pq.push(num);
        }
        while(min_pq.size() + 1 < max_pq.size()){
            int t = max_pq.top();
            max_pq.pop();
            min_pq.push(t);
        }
        while(max_pq.size() < min_pq.size()){
            int t = min_pq.top();
            min_pq.pop();
            max_pq.push(t);
        }
    }
    
    double findMedian() {
        if(min_pq.size() == max_pq.size()){
            return (min_pq.top() + max_pq.top()) / 2.0;
        }
        return max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
