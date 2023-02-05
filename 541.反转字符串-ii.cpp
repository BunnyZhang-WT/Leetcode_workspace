/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (58.72%)
 * Likes:    408
 * Dislikes: 0
 * Total Accepted:    169.8K
 * Total Submissions: 289.2K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 * 
 * 
 */

#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        // for (int i = 0; i < s.size(); ++i)
        // {
            // int index = i + k - 1;
            // if (index < s.size())
            // {
            //     for (int a=i,b=index; a<b; ++a,--b)
            //         swap(s[a], s[b]);
            // }
            // else
            // {
            //     for (int a=i,b=s.size()-1; a<b; ++a,--b)
            //         swap(s[a], s[b]);
            // }
            // i = index + k;   
        // }
        int len = s.length();
        for (int i = 0; i < len; i += 2*k)
            reverse(s.begin() + i, s.begin() + min(i + k, len));
        return s;
    }
};
// @lc code=end

