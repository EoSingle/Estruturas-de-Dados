#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infix_to_postfix(string infix) {
    stack<char> operators;
    stringstream postfix;

    for (char& c : infix) {
        if (isdigit(c)) {
            postfix << c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix << operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (isspace(c)) {
            continue;
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix << operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix << operators.top();
        operators.pop();
    }

    return postfix.str();
}

int evaluate_postfix(string postfix) {
    stack<int> operands;

    for (char& c : postfix) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else if (c == '+') {
            int a = operands.top(); operands.pop();
            int b = operands.top(); operands.pop();
            operands.push(b + a);
        } else if (c == '-') {
            int a = operands.top(); operands.pop();
            int b = operands.top(); operands.pop();
            operands.push(b - a);
        } else if (c == '*') {
            int a = operands.top(); operands.pop();
            int b = operands.top(); operands.pop();
            operands.push(b * a);
        } else if (c == '/') {
            int a = operands.top(); operands.pop();
            int b = operands.top(); operands.pop();
            operands.push(b / a);
        }
    }

    return operands.top();
}

int main() {
    string infix_expression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    string postfix_expression = infix_to_postfix(infix_expression);

    cout << "Infix: " << infix_expression << endl;
    cout << "Postfix: " << postfix_expression << endl;
    cout << "Result: " << evaluate_postfix(postfix_expression) << endl;

    return 0;
}

// Código gerado pelo chatGPT-3