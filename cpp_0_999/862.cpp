/*
 * 862. 和至少为 K 的最短子数组
 * 题意：如题，需要连续
 * 难度：困难
 * 分类：前缀和 双端队列
 * 算法：维持一个前缀和升序的队列(因为只需要考虑当前之前最小前缀和)，如果当前位置和队头合起来满足条件，队头就可以出队了，因为后续的元素都不如当前元素短
 */
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	vector<long long> presum(A.size()+1,0);
    	int i, minLen = INT_MAX, sum = 0;
    	deque<int> q;//存储下标，按照队内presum升序
    	q.push_back(0);//边界条件，前缀和为0，下标为0
    	for(i = 0; i < A.size(); ++i)
    	{
    		presum[i+1] = presum[i] + A[i];//前缀和
    		while(!q.empty() && presum[q.back()] >= presum[i+1])
    			q.pop_back();
    		while(!q.empty() && (presum[i+1]-presum[q.front()] >= K))
    		{
    			minLen = min(minLen, i+1-q.front());
    			q.pop_front();
    		}
    		q.push_back(i+1);
    	}
    	if(minLen == INT_MAX)
    		return -1;
    	return minLen;
    }
};
