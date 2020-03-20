/*
 * 399. 除法求值
 * 给定一些除法方程式，推导出一些除法方程式
 * 难度：中等
 * 分类：图 并查集
 * 算法：建hash表保存等式以及邻接，然后在图中使用宽度优先遍历
 */
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
