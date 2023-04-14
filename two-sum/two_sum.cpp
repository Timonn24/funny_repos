// https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::unordered_map<int, int> map; // val : indice
        for (std::size_t i = 0, c = nums.size(); i < c; ++i) {
            const int diff = target - nums[i];
            if (map.find(diff) != map.end()) {
                return std::vector<int> {map[diff], static_cast<int>(i)};
            }
            else {
                map[nums[i]] = i;
            }
        }
        return std::vector<int>();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}