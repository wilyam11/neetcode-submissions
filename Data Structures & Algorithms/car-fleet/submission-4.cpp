class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, int>> ps;
        for (int i = 0; i < n; ++i) {
            ps.push_back({position[i], speed[i]});
        }
        std::sort(ps.rbegin(), ps.rend());
        
        int count = 1;
        double top = static_cast<double> (target - ps[0].first) / ps[0].second;
        for(int i = 1; i < n; ++i) {
            double cur = static_cast<double> (target - ps[i].first) / ps[i].second;
            if (cur > top) {
                ++count;
                top = cur;
            }
        }
        return count;
    }
};
