class Solution {
public:
    int trap(vector<int>& height) {
        // O(1) memory
        int l = 0;
        int r = height.size() - 1;
        int sum = 0;
        int highest_left = 0;
        int highest_right = 0;
        while (l <= r) {
            if (highest_left > highest_right) {
                int x = std::min(highest_left, highest_right) - height[r];
                sum += std::max(0, x);
                highest_right = std::max(highest_right, height[r]);
                --r;
            } else {
                int x = std::min(highest_left, highest_right) - height[l];
                sum += std::max(0, x);
                highest_left = std::max(highest_left, height[l]);
                ++l;
            }
        }
        return sum;
    }
};
