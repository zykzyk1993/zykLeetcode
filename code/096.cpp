 /*
 * 96. 不同的二叉搜索树
 * 以1~n为节点的二叉搜索树有多少种
 * 难度：中等
 * 分类：树 dp
 * 算法：每增加一个，就可以分配到左右子树上，从而递推
 */
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
