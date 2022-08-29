#
# @lc app=leetcode id=326 lang=python3
#
# [326] Power of Three
#
# https://leetcode.com/problems/power-of-three/description/
#
# algorithms
# Easy (43.82%)
# Likes:    2012
# Dislikes: 191
# Total Accepted:    582.3K
# Total Submissions: 1.3M
# Testcase Example:  '27'
#
# Given an integer n, return true if it is a power of three. Otherwise, return
# false.
#
# An integer n is a power of three, if there exists an integer x such that n ==
# 3^x.
#
#
# Example 1:
#
#
# Input: n = 27
# Output: true
# Explanation: 27 = 3^3
#
#
# Example 2:
#
#
# Input: n = 0
# Output: false
# Explanation: There is no x where 3^x = 0.
#
#
# Example 3:
#
#
# Input: n = -1
# Output: false
# Explanation: There is no x where 3^x = (-1).
#
#
#
# Constraints:
#
#
# -2^31 <= n <= 2^31 - 1
#
#
#
# Follow up: Could you solve it without loops/recursion?
#

# @lc code=start
class Solution:
    """Check solution online for O(1), very interesting"""

    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True
        i = 1
        for _ in range(1, n):
            i *= 3
            if i == n:
                return True
            if i > n:
                break
        return False


# @lc code=end
