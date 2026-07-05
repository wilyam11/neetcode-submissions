class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> max_left(height.size());
        int hl = 0;
        for (int i = 0; i < height.size(); ++i) {
            max_left[i] = hl;
            hl = std::max(height[i], hl);
        }

        std::vector<int> max_right(height.size());
        int hr = 0;
        for (int i = height.size()-1; i >= 0; --i) {
            max_right[i] = hr;
            hr = (height[i] > hr)? height[i]: hr;
            hr = std::max(height[i], hr);
        }

        std::vector<int> min_bound(height.size());
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            min_bound[i] = std::min(max_left[i], max_right[i]);
            if (min_bound[i] - height[i] > 0) {
                sum += min_bound[i] - height[i];
            }
        }
        return sum;
    }
};
