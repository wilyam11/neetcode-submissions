class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n = nums.size();
        int l = 0, r = n-1;
        while (l <= r) {
            if (nums[l] <= nums[r]) {
                while (l <= r) {
                    int m = l + (r-l)/2;
                    cout << m << endl;
                    if (nums[m] == target) {
                        return m;
                    }
                    if (nums[m] > target) {
                        r = m - 1;
                    } else if (nums[m] < target) {
                        l = m + 1;
                    }
                }
                return -1;
            }
            int m = l + (r-l)/2;
            if (target == nums[m]) return m;
            if (target >= nums[l] && nums[l] >= nums[m]) {
                r = m - 1;
            } else if (target < nums[l] && nums[l] <= nums[m]) {
                l = m + 1;
            } else if (target > nums[m]) {
                l = m + 1;
            } else if (target < nums[m]) {
                r = m - 1;
            }
        }
        return -1;
    }
};
