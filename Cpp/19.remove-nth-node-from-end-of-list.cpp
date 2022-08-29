/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (39.06%)
 * Likes:    12052
 * Dislikes: 528
 * Total Accepted:    1.6M
 * Total Submissions: 4.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
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
private:
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p = head, *pdel = head, *prev = nullptr;
    for (int i = 0; i < n; i++)
      p = p->next;
    while (p != nullptr) {
      p = p->next;
      prev = pdel;
      pdel = pdel->next;
    }

    if (pdel == head) {
      head = pdel->next;
    } else if (pdel->next == nullptr) {
      prev->next = nullptr;
    } else {
      prev->next = pdel->next;
    }
    delete pdel;

    return head;
  }
};
// @lc code=end
