/*
 * 870. 优势洗牌
 * 题意：给定数组A B，将A洗牌，使A对应位置大于B的组数最多(田忌赛马)
 * 难度：中等
 * 分类：数组 贪心
 * 算法：1.多重集合保存A，对于B中每个数，找到upper_bound填入并erase，剩余元素随便排
 * 2. 先用vector<pair<int, int>> v保存位置，排序A，v(默认先对数值排序)，然后对v从大到小判定，A可以满足的情况从大了取，不能满足从小了塞
 */

//算法1
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> m(nums1.begin(), nums1.end());
        int n = nums1.size();
        vector<int> res(n, -1);
        for(int i = 0; i < n; i ++){
            auto itup = m.upper_bound(nums2[i]); //选取A中比B[i]的upper_bound
            if(itup == m.end()) continue;
            res[i] = *itup;
            m.erase(itup);
        }
        for(int i = 0; i < n; i ++){
            if(res[i] == -1){ //剩余元素随便排
                res[i] = *(m.begin());
                m.erase(m.begin());
            }
        }
        return res;
    }
};

//算法2
class Solution 
{
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)//方法2
    {
        vector<pair<int,int>>v;
        vector<int>ans(A.size(),-1);

        for(int i=0;i<B.size();i++)
            v.push_back(make_pair(B[i],i));//pair排序默认按第一关键字升序,若第一关键字相同再按第二关键字

        sort(A.begin(),A.end());
        sort(v.begin(),v.end());

        int Al = 0,Ar = A.size()-1,Br = v.size()-1;
        while(Br >= 0)
        {
            if(A[Ar] > v[Br].first)//Amax>Bmax  Amax去对位Bmax
            {
                ans[v[Br].second] = A[Ar];
                Ar--;
            }
            else//Amax<Bmax   Amin去对位Bmax
            {
                ans[v[Br].second] = A[Al];
                Al++;
            }
            Br--;
        }
        return ans;
    }
};
