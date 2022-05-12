/*
 * 440. 字典序的第K小数字
 * 题意：将1～n按照字典序排序，求第k个数
 * 难度：困难
 * 分类：字典树
 * 算法：将1～n看作字典树，增加辅助函数求以某数为根节点的树节点个数，然后cur_node从1开始，如果当前树节点超过k则下移，否则右移
 */
class Solution {
public:
    int count(long long now,long long n)
    {
        long long cur=now;
        long long next_one=now+1; // 下一个 左闭右开
        int res=0;
        while(cur<=n)
        {
            res+=min(next_one,n+1)-cur;
            next_one*=10;
            cur*=10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
        int cur_node=1;
        while(k>1)
        {
            int t=count(cur_node,n);
            if(t>=k)
            {
                cur_node*=10;
                k-=1;
            }
            else
            {
                cur_node+=1;
                k-=t;
            }
        }
        return cur_node;
    }
};
