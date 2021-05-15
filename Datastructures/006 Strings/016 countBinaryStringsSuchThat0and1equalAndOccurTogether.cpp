//https://leetcode.com/problems/count-binary-substrings/submissions/

class Solution {
public:
    int countBinarySubstrings(string s) {

        ios_base::sync_with_stdio(0); cin.tie(0);

        int cur = 1, pre = 0, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cur++;
            else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur, pre);
    }
};
