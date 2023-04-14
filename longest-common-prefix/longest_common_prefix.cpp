// https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static
    string longestCommonPrefix(vector<string>& strs) {
        std::size_t count = 0;
        bool equal = true;
        for (std::size_t col = 0; equal; ++col) {
            char tmp = '\0';
            for (std::size_t row = 0; equal && row < strs.size(); ++row) {
                if (strs[row].empty() || col >= strs[row].length()) {
                    equal = false;
                    break;
                }
                if (row && tmp != strs[row][col])
                    equal = false;
                tmp = strs[row][col];
            }
            if (equal)
                count++;
        }

        return strs[0].substr(0, count);
    }
};

int main()
{
    vector<string> v{ "flower", "flow", "flight" };
    _ASSERT(Solution::longestCommonPrefix(v) == "fl");

    vector<string> v2{ "dog", "racecar", "car" };
    _ASSERT(Solution::longestCommonPrefix(v2) == "");

    vector<string> v3{ "", "cat", "car" };
    _ASSERT(Solution::longestCommonPrefix(v3) == "");

    vector<string> v4{ "samurai", "", "" };
    _ASSERT(Solution::longestCommonPrefix(v4) == "");

    vector<string> v5{ "" };
    _ASSERT(Solution::longestCommonPrefix(v5) == "");

    vector<string> v6{ "a" };
    _ASSERT(Solution::longestCommonPrefix(v6) == "a");
}