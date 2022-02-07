/*
 * 443. 压缩字符串
 * 题意：将字符串压缩为字符加重复数量的字符数组保存，数量按位保存
 * 难度：中等
 * 分类：字符串
 * 算法：模拟，记录好数字，然后逐位保存后反向
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 0, idx = 0;
        char cur = chars[0];
        for(auto &c:chars) {
            if (c == cur) {
                cnt ++;
            }
            else {
                chars[idx++] = cur;
                if (cnt > 1) {
                    vector<int> temp;
                    while(cnt) {
                        temp.push_back(cnt % 10);
                        cnt /= 10;
                    }
                    for(int i = temp.size() - 1; i >= 0; i --) {
                        chars[idx++] = temp[i] + '0';
                    }
                }
                cur = c;
                cnt = 1;
            }
        }
        chars[idx++] = cur;
        if (cnt > 1) {
            vector<int> temp;
            while(cnt) {
                temp.push_back(cnt % 10);
                cnt /= 10;
            }
            for(int i = temp.size() - 1; i >= 0; i --) {
                chars[idx++] = temp[i] + '0';
            }
        }
        return idx;
    }
};
