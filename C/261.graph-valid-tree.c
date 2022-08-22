/*
 * @lc app=leetcode id=261 lang=c
 *
 * [261] Graph Valid Tree
 *
 * https://leetcode.com/problems/graph-valid-tree/description/
 *
 * algorithms
 * Medium (46.49%)
 * Likes:    2644
 * Dislikes: 76
 * Total Accepted:    293.1K
 * Total Submissions: 630.4K
 * Testcase Example:  '5\n[[0,1],[0,2],[0,3],[1,4]]'
 *
 * You have a graph of n nodes labeled from 0 to n - 1. You are given an
 * integer n and a list of edges where edges[i] = [ai, bi] indicates that there
 * is an undirected edge between nodes ai and bi in the graph.
 *
 * Return true if the edges of the given graph make up a valid tree, and false
 * otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2000
 * 0 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * There are no self-loops or repeated edges.
 *
 *
 */

// @lc code=start
#include <stdbool.h>

bool validTree(int n, int **edges, int edgesSize, int *edgesColSize) {
  if (edgesSize != n - 1)
    return false;
  bool checked[2000] = {false};
  // assume node i belongs to tree i
  int tree[2000];
  for (int i = 0; i < n; ++i)
    tree[i] = i;

  int min, max;

  for (int i = 0; i < edgesSize; ++i) {
    int from = edges[i][0], to = edges[i][1];
    if (checked[from] && checked[to]) {
      // cycle, or disjoint trees being merged
      if (tree[from] == tree[to])
        return false;
    }
    checked[from] = true;
    checked[to] = true;
    if (from > to) {
      min = to;
      max = from;
    } else {
      min = from;
      max = to;
    }

    int oldTreeNo = tree[max];
    for (int j = 0; j < n; ++j) {
      if (tree[j] == oldTreeNo)
        tree[j] = tree[min];
    }
  }

  return true;
}
// @lc code=end
