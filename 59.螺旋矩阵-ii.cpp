/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (74.32%)
 * Likes:    923
 * Dislikes: 0
 * Total Accepted:    276.3K
 * Total Submissions: 371.8K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int index = 1;
        int flag = 0;
        int row = 0, colum = 0;
        for (int i = 0; i < n*n; ++i)
        {
            matrix[row][colum] = i + 1;
            if (flag == 0)
            {
                if (colum == n - index)
                {
                    row++;
                    flag = 1;
                }
                else colum++;
            }
            else if (flag == 1)
            {
                if (row == n - index)
                {
                    colum--;
                    flag = 2;
                }
                else row++;
            }
            else if (flag == 2)
            {
                if (colum == index - 1)
                {
                    row--;
                    flag = 3;
                }
                else colum--;
            }
            else if (flag ==3)
            {
                if(row == index)
                {
                    colum++;
                    flag = 0;
                    index++;
                }
                else row--;
            }
        }
        return matrix;
    }
};
// @lc code=end

