class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max = 0;
        std::stack<std::pair<int, int>> ihstack;
        ihstack.push({0, heights[0]});
        for (int i = 1; i < n; ++i) {
            int left = i;
            while (!ihstack.empty() && ihstack.top().second > heights[i]) {
                int tmp = ihstack.top().second * (i - ihstack.top().first);
                max = (tmp > max)? tmp: max;
                left = ihstack.top().first;
                ihstack.pop();
            }
            ihstack.push({left, heights[i]});
        }
        while (!ihstack.empty()) {
            int tmp = ihstack.top().second * (n - ihstack.top().first);
            max = (tmp > max)? tmp: max;
            ihstack.pop();
        }
        return max;
    }
};
