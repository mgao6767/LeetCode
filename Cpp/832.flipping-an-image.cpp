/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 *
 * https://leetcode.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (80.12%)
 * Likes:    2469
 * Dislikes: 210
 * Total Accepted:    321.2K
 * Total Submissions: 400.5K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * Given an n x n binary matrix image, flip the image horizontally, then invert
 * it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is
 * reversed.
 *
 *
 * For example, flipping [1,1,0] horizontally results in [0,1,1].
 *
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is
 * replaced by 0.
 *
 *
 * For example, inverting [0,1,1] results in [1,0,0].
 *
 *
 *
 * Example 1:
 *
 *
 * Input: image = [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row:
 * [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * n == image.length
 * n == image[i].length
 * 1 <= n <= 20
 * images[i][j] is either 0 or 1.
 *
 *
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
    const auto len = image.front().size();
    for (auto &&vec : image) {
      for (size_t i = 0; i < len / 2; i++) {
        auto tmp = vec[i];
        vec[i] = 1 - vec[len - 1 - i];
        vec[len - 1 - i] = 1 - tmp;
      }
      if (len % 2 == 1)
        vec[len / 2] = 1 - vec[len / 2];
    }
    return image;
  }
};
// @lc code=end
