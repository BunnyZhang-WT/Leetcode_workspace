/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (56.84%)
 * Likes:    890
 * Dislikes: 0
 * Total Accepted:    440.4K
 * Total Submissions: 774.7K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给你两个整数数组 nums1 和 nums2
 * ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[4,9]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 * 
 * 
 */
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// 哈希表
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> hashmap;
//         vector<int> output;
//         if (nums1.size() > nums2.size())
//         {
//             return intersect(nums2, nums1);
//             // vector<int> nums3 = nums2;
//             // nums2 = nums1;
//             // nums1 = nums3;
//         }
//         for (int i = 0; i < nums1.size(); ++i)
//         {
//             ++hashmap[nums1[i]];
//             // if(hashmap.find(nums1[i]) == hashmap.end())
//             //     hashmap[nums1[i]] = 1;
//             // else
//             //    ++ hashmap[nums1[i]];
//         }
//         for (int j = 0; j < nums2.size(); ++j)
//         {
//             if(hashmap.find(nums2[j]) != hashmap.end())
//             {
//                 output.emplace_back(nums2[j]);
//                 --hashmap[nums2[j]];
//                 if (hashmap[nums2[j]] == 0)
//                     hashmap.erase(nums2[j]);
//             }
//         }
//         return output;
//     }
// };

// 排序+双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        vector<int> output;
        int index1 = 0, index2 = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (index1 < nums1.size() && index2 < nums2.size())
        {
            if (nums1[index1] < nums2[index2])
                ++index1;
            else if (nums1[index1] > nums2[index2])
                ++index2;
            else
            {
                output.emplace_back(nums1[index1]);
                ++index1;
                ++index2;
            }
        }     
        return output;
    }
};
