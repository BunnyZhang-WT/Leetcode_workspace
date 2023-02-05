/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode.cn/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (55.75%)
 * Likes:    635
 * Dislikes: 0
 * Total Accepted:    361.2K
 * Total Submissions: 647.7K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "leetcode"
 * 输出: 0
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "loveleetcode"
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "aabb"
 * 输出: -1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含小写字母
 * 
 * 
 */
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
// @lc code=start

// 哈希表
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         unordered_map<int, int> hashmap;
//         for (int i = 0; i < s.length(); ++i)
//             hashmap[s[i]]++;
//         for (int j = 0; j < s.length(); ++j)
//             if (hashmap[s[j]] == 1)
//                 return j;
//         return -1;
//     }
// };

// 哈希表+队列
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        queue<pair<char, int>> q;
        for (int i = 0; i < s.length(); ++i)
        {
            if (hashmap.count(s[i]))
            {
                hashmap[s[i]] = -1;
                while (hashmap[q.front().first] == -1 && !q.empty())
                    q.pop();
            }
            else
            {
                hashmap[s[i]] = i;
                q.emplace(s[i], i);
            }
        }
        return q.empty() ? -1 : q.front().second;
    }
};

// @lc code=end

