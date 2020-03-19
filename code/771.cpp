class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, bool> mp;
        int sum = 0;
        for (auto j : J)
            mp[j] = 1;
        for (auto s : S)
            if (mp[s]) sum++;
        return sum;
    }
};
