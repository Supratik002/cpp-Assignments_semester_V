#include <iostream>
#include <string>
#include <stack>

class Expr {
private:
    std::string expression;

    // Helper function to perform operations
    int applyOperation(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }

    // Helper function to check precedence of operators
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

public:
    // Constructor
    Expr(const char* expr) : expression(expr) {}

    // Function to evaluate the expression
    int eval() {
        std::stack<int> values;
        std::stack<char> ops;
        int n = expression.size();

        for (int i = 0; i < n; i++) {
            // If the current character is a digit, push it to the values stack
            if (isdigit(expression[i])) {
                values.push(expression[i] - '0');  // Convert char to int
            }

            // If the current character is an operator
            else if (expression[i] == '+' || expression[i] == '-' ||
                     expression[i] == '*' || expression[i] == '/') {
                // While the top of the ops stack has greater or equal precedence to the current operator
                // apply the operator on the top of the stack to the top two elements in the values stack
                while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                    int val2 = values.top(); values.pop();
                    int val1 = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOperation(val1, val2, op));
                }
                // Push current operator to ops stack
                ops.push(expression[i]);
            }
        }

        // Apply remaining operators to the remaining values
        while (!ops.empty()) {
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(applyOperation(val1, val2, op));
        }

        // The final value on the stack is the result
        return values.top();
    }

    // Function to print the expression
    void print() {
        std::cout << "Expression: " << expression << std::endl;
    }
};

int main() {
    Expr x("8/4+3*4-3");
    std::cout << "x = " << x.eval() << "\n";
    x.print();
    return 0;
}
