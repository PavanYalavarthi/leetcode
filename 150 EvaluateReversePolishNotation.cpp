/*
 * Time complexity : O(n)
 * Space complexity : O(n)
 * push operands to stack and pop when operator comes
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operandStack;
        int result;
        for(string token : tokens) {
            if(token.size() > 1 || isdigit(token[0])){
                result = stoi(token);
            } else {
                char op = token[0];
                int right = operandStack.top();
                operandStack.pop();
                int left = operandStack.top();
                operandStack.pop();
                if (op == '+') result = left + right;
                else if (op == '-') result = left - right;
                else if (op == '*') result = left * right;
                else result = left / right;
            }
            operandStack.push(result);
        }
        return operandStack.top();
    }
};