/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (62.84%)
 * Likes:    11922
 * Dislikes: 383
 * Total Accepted:    1.4M
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 *
 *
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 *
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  // Boyer-Moore Majority Vote Algorithm
  int majorityElement(vector<int> &nums) {
    auto elm = nums[0];
    auto times = 1;
    for (size_t i = 1; i < nums.size(); i++) {
      if (times == 0) {
        times++;
        elm = nums[i];
      } else if (elm == nums[i]) {
        times++;
      } else
        times--;
    }
    return elm;
  }
};
// @lc code=end
