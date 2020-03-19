class Solution {
public:
    int hammingDistance(int x, int y){
        int cnt = 0, num = x ^ y;
        while(num > 0)
        {
            if(num % 2 == 1) ++cnt;
            num /= 2;
        }
        return cnt;
    }
};
