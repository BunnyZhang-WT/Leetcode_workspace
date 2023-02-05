/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (73.45%)
 * Likes:    2934
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
 * 
 * 
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// #include<stack>
// using namespace std;
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head)
//             return head;
//         stack<ListNode*> stk;
//         while (head)
//         {
//             stk.emplace(head);
//             head = head->next;
//         }
//         ListNode* rev = stk.top();
//         ListNode* dummy = rev;
//         stk.pop();
//         while (!stk.empty())
//         {
//             rev->next = stk.top();
//             stk.pop();
//             rev = rev->next;
//         }
//         rev->next = nullptr;
//         return dummy;
//     }
// };

// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* reverse = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reverse;
    }
};

// @lc code=end

