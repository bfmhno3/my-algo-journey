#include <iostream>
#include <stack>
#include <string>

int main(void) {
    std::stack<int> stk;
    std::string expression;
    std::string num_str;
    int num = 0;
    int result = 0;

    std::cin >> expression;

    for (const char& ch : expression) {
        if (ch == '@') break;
    
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            num_str += ch;
        } else if (ch == '.') {
            if (!num_str.empty()) {
                stk.push(std::stoi(num_str));
                num_str.clear();
            }
        } else {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            int result = 0;
            switch (ch) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
            }
            stk.push(result);
        }
    }

    result = stk.top();

    std::cout << result << std::endl;

    return 0;
}
