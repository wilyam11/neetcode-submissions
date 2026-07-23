class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<double> eta(position.size(), 0);

        int n = position.size();
        vector<pair<int, int>> paired(n);
        
        for (int i = 0; i < n; ++i) {
            paired[i] = {position[i], speed[i]};
        }

        // std::sort automatically sorts pairs by the FIRST element (position)
        sort(paired.begin(), paired.end());

        // Write back the sorted results into the original reference vectors
        for (int i = 0; i < n; ++i) {
            position[i] = paired[i].first;
            speed[i]    = paired[i].second;
        }

        std::stack<double> fleetstack;
        for (int i = 0; i < position.size(); ++i) {
            eta[i] = static_cast<double>(target - position[i]) / speed[i];
            while(!fleetstack.empty() && fleetstack.top() <= eta[i]) {
                fleetstack.pop();
            }
            fleetstack.push(eta[i]);
        }
        return fleetstack.size();
    }
};


