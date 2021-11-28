/*
 * 399. 除法求值
 * 给定一些除法方程式，推导出一些除法方程式
 * 难度：中等
 * 分类：图 并查集
 * 算法：建hash表保存等式以及邻接，然后在图中使用宽度优先遍历
 */
//2021 floyd算法
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> hash;
        int cnt=0;
        int n=equations.size();
        for(int i=0;i<n;i++){
            if(hash.find(equations[i][0])==hash.end())hash[equations[i][0]]=cnt++;
            if(hash.find(equations[i][1])==hash.end())hash[equations[i][1]]=cnt++;
        }
        vector<vector<double>> graph(cnt,vector<double>(cnt,-1));
        for(int i=0;i<n;i++){
            graph[hash[equations[i][0]]][hash[equations[i][1]]]=values[i];
            graph[hash[equations[i][1]]][hash[equations[i][0]]]=1.0/values[i];
            graph[i][i]=1;
        }
        for(int k=0;k<cnt;k++){
            for(int i=0;i<cnt;i++){
                for(int j=0;j<cnt;j++){
                    if(graph[i][j]<0&&graph[i][k]>=0&&graph[k][j]>=0)graph[i][j]=graph[i][k]*graph[k][j];
                }
            }
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            if(hash.find(queries[i][0])==hash.end()||hash.find(queries[i][1])==hash.end())ans.push_back(-1);
            else ans.push_back(graph[hash[queries[i][0]]][hash[queries[i][1]]]);
        }
        return ans;
    }
};

class Solution {
public:
    double cal(string a, string b, map<pair<string,string>,double> &m, map<string,vector<string>> &eqs){
        queue<string> q;
        q.push(a);
        unordered_set<string> visited;
        visited.insert(a);
        while(!q.empty()){
            string curString=q.front();
            q.pop();
            vector<string> nextS=eqs[curString];
            for(auto c:nextS){
                if(visited.count(c)){
                    continue;
                }
                visited.insert(c);
                q.push(c);
                double res = m[make_pair(a,curString)]*m[make_pair(curString,c)];
                m[make_pair(a,c)]=res;
                m[make_pair(c,a)]=1.0/res;
                eqs[a].push_back(c);
                eqs[c].push_back(a);
                if(c==b){
                    return res;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> s;
        map<pair<string,string>,double> m;
        map<string,vector<string>> eqs;
        vector<double> ans;
        for(int i=0;i<values.size();i++){
            vector<string> equation=equations[i];
            string a=equation[0],b=equation[1];
            s.insert(a);
            s.insert(b);
            m[make_pair(a,b)]=values[i];
            m[make_pair(b,a)]=1.0/values[i];
            eqs[a].push_back(b);
            eqs[b].push_back(a);
        }
        for(auto c:s){
            m[make_pair(c,c)]=1.0;
        }
        for(int i=0;i<queries.size();i++){
            vector<string> querie=queries[i];
            string a=querie[0],b=querie[1];
            if(s.count(a)==0||s.count(b)==0){
                ans.push_back(-1.0);
                continue;
            }
            if(m.count(make_pair(a,b))!=0){
                ans.push_back(m[make_pair(a,b)]);
                continue;
            }
            ans.push_back(cal(a,b,m,eqs));
        }
        return ans;
    }
};
