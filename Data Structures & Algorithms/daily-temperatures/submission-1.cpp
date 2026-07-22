class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> tempstack;
        for (int i = 0; i < temperatures.size(); ++i) {
            if (!tempstack.empty()) {
                int cur = tempstack.top();
                while (!tempstack.empty() && temperatures[i] > temperatures[cur]) {
                    result[cur] = i - cur;
                    tempstack.pop();
                    cur = tempstack.top();
                }
            }
            tempstack.push(i);
        }
        return result;
    }
};
