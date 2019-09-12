class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(string str:strs){
            string temp=str;
            sort(str.begin(),str.end());
            m[str].push_back(temp);
        }
        unordered_map<string,vector<string>>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};
