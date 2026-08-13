class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int max = -1;
        for (int i = 0; i < n; i++) {
            if (max < piles[i]) {
                max = piles[i];
            }
        }
        cout << max << endl;
        int l = 1;
        int r = max;
        int k = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            int t = 0;
            for (int i = 0; i < n; i++) {
                t += (piles[i]%mid == 0)? piles[i]/mid:
                piles[i]/mid + 1;
            }
            if (t > h) {
                l = mid+1;
            } else if (t <= h) {
                k = mid;
                r = mid-1;
            }
        }
        return k;
    }
};
