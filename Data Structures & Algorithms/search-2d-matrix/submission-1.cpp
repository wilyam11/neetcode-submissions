class Solution {
private:
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        int mid;
        while (low <= high) {
            mid = (low+high)/2;
            if (mid == m-1) break;
            if (matrix[mid][0] <= target && 
                matrix[mid+1][0] > target) {
                break;
            }
            if (matrix[mid][0] > target) {
                high = mid - 1;
            } else if (matrix[mid][0] < target) {
                low = mid+1;
            }
        }
        int l = 0;
        int r = n-1;
        while (l <= r) {
            int mid1 = (l+r)/2;
            if (matrix[mid][mid1] == target) {
                return true;
            }
            if (matrix[mid][mid1] < target) {
                l = mid1 + 1;
            } else if (matrix[mid][mid1] > target) {
                r = mid1 - 1;
            }
        }
        return false;
    }
};
