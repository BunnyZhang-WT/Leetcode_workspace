/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (52.85%)
 * Likes:    1603
 * Dislikes: 0
 * Total Accepted:    546.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 */

// @lc code=start

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// #include <vector>
// using namespace std;
// class Solution
// {
// public:
//     bool isPalindrome(ListNode *head)
//     {
//         vector<int> vec;
//         while (head != nullptr)
//         {
//             vec.emplace_back(head->val);
//             head = head->next;
//         }

//         for (int left = 0, right = vec.size() - 1; left < right; ++left, --right)
//         {
//             if (vec[left] != vec[right])
//                 return false;
//         }
//         return true;
//     }
// };

// 快慢指针
// class Solution
// {
// public:
//     ListNode *reverse(ListNode *head)
//     {
//         ListNode *prev = nullptr;
//         while (head != nullptr)
//         {
//             ListNode *next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
//         return prev;
//     }

//     bool isPalindrome(ListNode *head)
//     {
//         ListNode *fast = head, *slow = head;
//         while (fast != nullptr && fast->next != nullptr)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         if (fast != nullptr)
//             slow = slow->next;
//         slow = reverse(slow);

//         while (slow != nullptr)
//         {
//             if (slow->val != head->val)
//                 return false;
//             slow = slow->next;
//             head = head->next;
//         }

//         return true;
//     }
// };

// 递归
class Solution
{
public:
    ListNode *temp;
    bool isPalindrome(ListNode *head)
    {
        temp = head;
        return helper(head);
    }

    bool helper(ListNode *head)
    {
        if (head == nullptr)
            return true;
        bool out = helper(head->next) && (temp->val == head->val);
        temp = temp->next;
        return out;
    }
};
// @lc code=end
