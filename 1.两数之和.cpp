/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
using namespace std;

// @lc code=start

// 暴力解法
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int length = nums.size();
//         for(int i=0;i<length-1;i++)
//         {
//             for(int j=i+1;j<length;j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                     return {i,j};
//             }
//         }
//         return {};
//     }
// };

// 哈希表
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if(hashmap.count(target - nums[i]) > 0)
            {
                return {hashmap[target - nums[i]], i};
            }
            hashmap[nums[i]] = i;
        }
        return {};
        // hashmap.insert(pair<int, int>(nums[0], 0));   
        // for (int i = 1; i < length; i++)
        // {
        //     auto it = hashmap.find(target - nums[i]);
        //     if (it != hashmap.end()) //
        //     {
        //         return {it->second, i};
        //     }
        //     hashmap.insert(pair<int, int>(nums[i], i));           
        // }
        // return {};
    }
};
// @lc code=end

