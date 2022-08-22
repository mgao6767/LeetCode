/*
 * @lc app=leetcode id=323 lang=c
 *
 * [323] Number of Connected Components in an Undirected Graph
 *
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
 *
 * algorithms
 * Medium (61.69%)
 * Likes:    2143
 * Dislikes: 70
 * Total Accepted:    280.6K
 * Total Submissions: 454.6K
 * Testcase Example:  '5\n[[0,1],[1,2],[3,4]]'
 *
 * You have a graph of n nodes. You are given an integer n and an array edges
 * where edges[i] = [ai, bi] indicates that there is an edge between ai and bi
 * in the graph.
 *
 * Return the number of connected components in the graph.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5, edges = [[0,1],[1,2],[3,4]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2000
 * 1 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai <= bi < n
 * ai != bi
 * There are no repeated edges.
 *
 *
 */

// @lc code=start
#include <stdbool.h>

#define N 2000
typedef unsigned short us;

int countComponents(int n, int **edges, int edgesSize, int *edgesColSize) {

  bool comp[N] = {false};
  us tree[N];
  for (int i = 0; i < n; i++)
    tree[i] = i;

  int min, max;
  for (int i = 0; i < edgesSize; i++) {
    int s = edges[i][0], t = edges[i][1];
    if (s < t) {
      min = s;
      max = t;
    } else {
      min = t;
      max = s;
    }
    int oldTreeNo = tree[max];
    for (int k = 0; k < n; k++) {
      if (tree[k] == oldTreeNo) {
        tree[k] = tree[min];
      }
    }
  }

  // find #distinct values in tree[]
  for (int i = 0; i < n; i++)
    comp[tree[i]] = true;
  int comps = 0;
  for (int i = 0; i < n; i++)
    comps += comp[i];

  return comps;
}
// @lc code=end
