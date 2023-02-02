/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (47.45%)
 * Likes:    1542
 * Dislikes: 0
 * Total Accepted:    475.3K
 * Total Submissions: 1M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 * 
 * 
 */

#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         // int min_len = 0;
//         int min_len = INT_MAX;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             int sum = 0, len = 0;
            
//             // 超时
//             // while (sum < target && i + len < nums.size())
//             // {
//             //     sum += nums[i + len];
//             //     len++;
//             // }
//             // if (sum >= target && (i == 0 || len < min_len))
//             //     min_len = len;
//             // if ((sum < target) && (i + len == nums.size()))
//             //     return min_len;

//             // 同样超时
//             for (int j = i; j < nums.size(); ++j)
//             {
//                 sum += nums[j];
//                 len++;
//                 if(sum >= target)
//                 {
//                     min_len = min(len, min_len);
//                     break;
//                 }
//             }
//         }
//         if (min_len == INT_MAX)
//             return 0;
//         return min_len;
//     }
// };

// 滑动窗口法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int length = INT_MAX;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= target)
            {
                length = min(length, right-left+1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if (length == INT_MAX)
            return 0;
        return length;
    }
};
// @lc code=end

