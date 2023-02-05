/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.53%)
 * Likes:    2885
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两个链表的节点数目范围是 [0, 50]
 * -100
 * l1 和 l2 均按 非递减顺序 排列
 *
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

// 一个插入另一个
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         ListNode *list;
//         if (list1 == nullptr)
//             return list2;
//         if (list2 == nullptr)
//             return list1;

//         if (list1->val < list2->val)
//             list = helper(list1, list2);
//         else
//             list = helper(list2, list1);

//         return list;
//     }

//     ListNode *helper(ListNode *list1, ListNode *list2)
//     {
//         ListNode *list = new ListNode(0, list1);
//         while (list1 != nullptr || list2 != nullptr)
//         {
//             if (list1->next == nullptr)
//             {
//                 list1->next = list2;
//                 return list->next;
//             }
//             else if (list2 == nullptr)
//                 return list->next;

//             if (list1->next->val > list2->val)
//             {
//                 ListNode *temp1 = list1->next;
//                 ListNode *temp2 = list2->next;
//                 list1->next = list2;
//                 list2->next = temp1;
//                 list2 = temp2;
//             }

//             list1 = list1->next;
//         }
//         return list->next;
//     }
// };

// 新链表存储表头
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         //下面4行是空判断
//         if (list1 == nullptr)
//             return list2;
//         if (list2 == nullptr)
//             return list1;
//         ListNode *dummy = new ListNode(0);
//         ListNode *curr = dummy;
//         while (list1 != nullptr && list2 != nullptr)
//         {
//             //比较一下，哪个小就把哪个放到新的链表中
//             if (list1->val <= list2->val)
//             {
//                 curr->next = list1;
//                 list1 = list1->next;
//             }
//             else
//             {
//                 curr->next = list2;
//                 list2 = list2->next;
//             }
//             curr = curr->next;
//         }
//         //然后把那个不为空的链表挂到新的链表中
//         curr->next = list1 == nullptr ? list2 : list1;
//         return dummy->next;
//     }
// };

// 递归
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
// @lc code=end
