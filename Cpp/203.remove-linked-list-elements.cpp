/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (44.30%)
 * Likes:    5735
 * Dislikes: 181
 * Total Accepted:    781.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Given the head of a linked list and an integer val, remove all the nodes of
 * the linked list that has Node.val == val, and return the new head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [], val = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 10^4].
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *p = head, *prev = nullptr;
    while (p != nullptr) {
      if (p->val != val) {
        prev = p;
        p = p->next;
      } else {
        if (p == head) {
          head = p->next;
        } else if (p->next == nullptr) {
          prev->next = nullptr;
        } else {
          prev->next = p->next;
        }
        auto del = p;
        p = p->next;
        if (del != nullptr)
          delete del;
      }
    }
    return head;
  }
};
// @lc code=end
