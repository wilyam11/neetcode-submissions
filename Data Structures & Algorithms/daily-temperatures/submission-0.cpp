class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> tempstack;
        std::vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            if (!tempstack.empty()) {
                std::pair<int, int> current = tempstack.top();
                while (!tempstack.empty() && current.second < temperatures[i]) {
                    result[current.first] = i - current.first;
                    tempstack.pop();
                    current = tempstack.top();
                }
            }
            tempstack.emplace(i, temperatures[i]);
        }
        return result;
    }
};
