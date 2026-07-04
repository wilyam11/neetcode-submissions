class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> operands;
        operands.reserve(tokens.size());
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                int num = std::stoi(tokens[i]);
                operands.push_back(num);
            } else {
                int operand2 = operands.back();
                operands.pop_back();
                int operand1 = operands.back();
                operands.pop_back();
                int res;
                switch (tokens[i][0]) {
                    case '+': res = operand1 + operand2; break;
                    case '-': res = operand1 - operand2; break;
                    case '*': res = operand1 * operand2; break;
                    case '/': res = operand1 / operand2; break;
                }
                operands.push_back(res);
            }
        }
        int ans = operands.back();
        return ans;
    }
};
