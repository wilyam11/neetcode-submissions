class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        std::stack<std::pair<int, int>> heightandstart;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int left = i;
            while (!heightandstart.empty() && 
                    heightandstart.top().first > heights[i]) {
                int height = heightandstart.top().first;
                left = heightandstart.top().second;
                maxi = max(height*(i-left), maxi);
                heightandstart.pop();
            }
            heightandstart.push(pair(heights[i], left));
        }
        while (!heightandstart.empty()) {
            int height = heightandstart.top().first;
            int left = heightandstart.top().second;
            maxi = max(height*(n-left), maxi);
            heightandstart.pop();
        }
        return maxi;
    }
};
