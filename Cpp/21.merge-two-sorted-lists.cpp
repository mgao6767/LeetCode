/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (61.33%)
 * Likes:    14437
 * Dislikes: 1284
 * Total Accepted:    2.5M
 * Total Submissions: 4.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists in a one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: list1 = [], list2 = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 *
 *
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

class Solution {

public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *p1 = list1, *p2 = list2, *p = new ListNode();
    auto phead = p;
    while (p1 != nullptr || p2 != nullptr) {
      if (p1 == nullptr) {
        p->next = new ListNode(p2->val);
        p2 = p2->next;
      } else if (p2 == nullptr) {
        p->next = new ListNode(p1->val);
        p1 = p1->next;
      } else if (p1->val < p2->val) {
        p->next = new ListNode(p1->val);
        p1 = p1->next;
      } else {
        p->next = new ListNode(p2->val);
        p2 = p2->next;
      }
      p = p->next;
    }
    p = phead->next;
    delete phead;
    return p;
  }
};
// @lc code=end
