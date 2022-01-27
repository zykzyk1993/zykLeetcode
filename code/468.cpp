/*
 * 468. 验证IP地址
 * 题意：验证是否是符合条件的IPV4或IPV6地址
 * 难度：中等
 * 分类：字符串
 * 算法：模拟，分开判断
 */

class Solution {
public:
    bool isIPv4(string queryIP) {
        int dot_num = 0, cur_num = 0;
        for(int i = 0; i < queryIP.size(); i ++) {
            char c = queryIP[i];
            if (c == '.') {
                if(dot_num > 2) {
                    return false;
                }
                if(i > 0 && queryIP[i-1] == '.') {
                    return false;
                }
                if(i == queryIP.size() - 1) {
                    return false;
                }
                dot_num ++;
                cur_num = 0;
            }
            else if(c >= '0' && c<= '9') {
                if (c == '0' && cur_num == 0) {
                    if (i < queryIP.size() - 1 && queryIP[i+1] != '.') {
                        return false;
                    }
                }
                cur_num = cur_num * 10 + (c - '0');
                if(cur_num > 255) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return (dot_num == 3);
    }
    bool isIPv6Part(string part) {
        if(part.size() == 0 || part.size() > 4) {
            return false;
        }
        for (auto &c:part) {
            if (c >= '0' && c <= '9') {
                continue;
            }
            if (c >= 'a' && c <= 'f') {
                continue;
            }
            if (c >= 'A' && c <= 'F') {
                continue;
            }
            return false;
        }
        return true;
    }
    bool isIPv6(string queryIP) {
        string part;
        int part_num = 0;
        for(auto c:queryIP) {
            if (c == ':') {
                if (part_num > 6) {
                    return false;
                }
                part_num ++;
                if (!isIPv6Part(part)) {
                    return false;
                }
                part = "";
            }
            else {
                part += c;
            }
        }
        if (!isIPv6Part(part)) {
            return false;
        }
        return (part_num == 7);
    }
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) {
            return "IPv4";
        }
        if (isIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }
};
