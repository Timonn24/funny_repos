#include <iostream>
#include <string>
#include <stack>

using namespace std;
// https://leetcode.com/problems/valid-parentheses/
/*
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

s = "{}" => true
s = "()[]{}" => true
s = "(]" => false

()(){([])}

*/
class Solution {
public:
    bool isValid(string s) {
        std::stack<std::string::value_type> stack;
        for(std::size_t i = 0; i < s.length(); ++i) {
            const char ch = s[i];
            if(isOpening(ch)) {
                stack.push(ch);
            } else if(isClosing(ch)) {
                if(stack.size() && match(stack.top(), ch))
                    stack.pop();
                else
                    return false;
            }
        }

        return stack.empty();
    }
private:
    static bool isOpening(const std::string::value_type& c) noexcept {
        return (c == '{' || c == '(' || c == '[');
    }
    static bool isClosing(const std::string::value_type& c) noexcept {
        return (c == '}' || c == ')' || c == ']');
    }
    static bool match(const std::string::value_type& l, const std::string::value_type& r) noexcept {
        return (l == '{' && r == '}') || (l == '(' && r == ')') || (l == '[' && r == ']');
    }
};

int main() {
    Solution sl;
    std::string test1 = "}";
    std::cout << test1 << " is valid:" << sl.isValid(test1);

    return 0;
}