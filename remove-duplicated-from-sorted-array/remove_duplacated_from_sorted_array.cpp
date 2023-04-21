// RemoveDuplicatedFromSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() <= 1)
            return nums.size();

        // At least, nums[0] is unique.
        int itracker = 1;

        for (std::size_t i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] != nums[i + 1]) {
                nums[itracker] = nums[i + 1];
                itracker++;
            }
        }
        return itracker;
    }
};


int main()
{
    vector<int> data{ 0,0,1,1,1,2,2,3,3,4 };

    int k = Solution::removeDuplicates(data);
    data.resize(k);
}