class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        std::unordered_map<char, int> chartoidx;
        int n = s.size();
        int j = 0;
        int start = 0;
        int maxlen = 0;
        while (j < n) {
            char c = s[j];
            if (chartoidx.find(c) != chartoidx.end()) {
                start = max(chartoidx[c] + 1, start); 
            }
            chartoidx[c] = j;
            maxlen = max(maxlen, j - start + 1);
            j++;
        }
        return maxlen;
    }
};
