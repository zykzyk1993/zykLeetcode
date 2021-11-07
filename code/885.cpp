/*
 * 882. 细分图中的可到达结点
 * 题意：给定图，每个图结点之间的细分结点数目，以及最大移动次数，求可以达到多少个结点
 * 难度：困难
 * 分类：图
 * 算法：Dijkstra计算单源最短路径，然后判断每个结点之间的子结点可以到达几个
 */
class Solution {
public:
    vector<vector<int>> initGraph(vector <vector<int>> &edges, int n) {
      vector <vector<int>> G(n, vector<int>(n, INT_MIN));
      for (auto &e:edges) {
        G[e[0]][e[1]] = e[2] + 1;
        G[e[1]][e[0]] = e[2] + 1;
      }
      return G;
    }

    vector<int> Dijkstra(int n, vector <vector<int>> &G, vector<int>& pre) {
        const int INF = 1000000000;
      vector<bool> vis(n, false);
      vector<int> d(n, INF);
      d[0] = 0;     
      for (int i = 0; i < n; ++i)                           
        pre[i] = i;
                                        
      for (int i = 0; i < n; ++i) {
        int u = -1;                                    
        int MIN = INF;                               
        for (int j = 0; j < n; ++j)                     //开始寻找最小的d[u]
        {
          if (vis[j] == false && d[j] < MIN) {
            u = j;
            MIN = d[j];
          }
        }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1)
          return d;
        vis[u] = true;                                  //标记u已被访问
        for (int v = 0; v < n; ++v) {
          //遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
          if (vis[v] == false && G[u][v] >= 0 && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];             //更新d[v]
                pre[v] = u;
          }
        }
      }
      return d;
    }

    int reachableNodes(vector <vector<int>> &edges, int maxMoves, int n) {
        vector<vector<int>> G = initGraph(edges, n);
        vector<int> pre(n, 0);
        vector<int> d = Dijkstra(n, G, pre);
        int res = 1;
        vector<bool> vis(n, false);
        vis[0] = true;
        for(auto &e:edges){
            if(d[e[0]] <= maxMoves &&!vis[e[0]]){
                vis[e[0]] = true;
                res ++;
            }
            if(d[e[1]] <= maxMoves && !vis[e[1]]){
                vis[e[1]] = true;
                res ++;
            }
            int extra = 0;
            extra+=max(0, maxMoves - d[e[0]]);
            extra+=max(0, maxMoves - d[e[1]]);
            extra=min(extra, e[2]);
            res += extra;
        }
        return res;
    }
};
