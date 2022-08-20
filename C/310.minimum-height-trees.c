/*
 * @lc app=leetcode id=310 lang=c
 *
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (38.35%)
 * Likes:    5805
 * Dislikes: 242
 * Total Accepted:    215.5K
 * Total Submissions: 561.9K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * A tree is an undirected graph in which any two vertices are connected by
 * exactly one path. In other words, any connected graph without simple cycles
 * is a tree.
 *
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1
 * edgesOf where edgesOf[i] = [ai, bi] indicates that there is an undirected
 * edge between the two nodes ai and bi in the tree, you can choose any node of
 * the tree as the root. When you select a node x as the root, the result tree
 * has height h. Among all possible rooted trees, those with minimum height
 * (i.e. min(h))  are called minimum height trees (MHTs).
 *
 * Return a list of all MHTs' root labels. You can return the answer in any
 * order.
 *
 * The height of a rooted tree is the number of edgesOf on the longest downward
 * path between the root and a leaf.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, edgesOf = [[1,0],[1,2],[1,3]]
 * Output: [1]
 * Explanation: As shown, the height of the tree is 1 when the root is the node
 * with label 1 which is the only MHT.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 6, edgesOf = [[3,0],[3,1],[3,2],[3,4],[5,4]]
 * Output: [3,4]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2 * 10^4
 * edgesOf.length == n - 1
 * 0 <= ai, bi < n
 * ai != bi
 * All the pairs (ai, bi) are distinct.
 * The given input is guaranteed to be a tree and there will be no repeated
 * edgesOf.
 *
 *
 */

#include <stdlib.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef unsigned short ushort;
int *findMinHeightTrees(int n, int **edges, int edgesSize, int *edgesColSize,
                        int *returnSize) {
  *returnSize = 0;
  int *result = malloc(n * sizeof(int));
  if (n == 1) {
    result[(*returnSize)++] = 0;
    return result;
  }
  ushort *queue = malloc(sizeof(ushort) * n);
  ushort *inDegree = calloc(n, sizeof(ushort));
  ushort *nEdges = calloc(n, sizeof(ushort));
  ushort *edgesOf = malloc(n * 20000 * sizeof(ushort));
  ushort queueEnd = 0, queueStart = 0, defaultNumEdges = 20000;

  for (int i = 0; i < edgesSize; i++) {
    int s = edges[i][0], t = edges[i][1];
    inDegree[s]++;
    inDegree[t]++;
    // if ((inDegree[s] > defaultNumEdges) || (inDegree[t] > defaultNumEdges)) {
    //   int newNumEdges = defaultNumEdges * 2;
    //   edgesOf = realloc(edgesOf, sizeof(int) * n * newNumEdges);
    //   for (int k = n - 1; k > 0; k--) {
    //     for (int p = defaultNumEdges - 1; p >= 0; p--) {
    //       edgesOf[k * newNumEdges + p] = edgesOf[k * defaultNumEdges + p];
    //     }
    //   }
    //   defaultNumEdges = newNumEdges;
    // }
    edgesOf[s * defaultNumEdges + nEdges[s]++] = t;
    edgesOf[t * defaultNumEdges + nEdges[t]++] = s;
  }
  // enqueue leaf nodes with indegree of 1
  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 1) {
      queue[queueEnd++] = i;
      inDegree[i] = 0;
    }
  }

  while ((queueEnd - queueStart > 0)) {
    *returnSize = 0;
    ushort queueEndPrev = queueEnd;
    for (ushort i = queueStart; i < queueEndPrev; i++) {
      ushort node = queue[i];
      int offset = node * defaultNumEdges;
      result[(*returnSize)++] = node;
      for (ushort k = 0; k < nEdges[node]; k++) {
        ushort parent = edgesOf[offset + k];
        inDegree[parent]--;
        if (inDegree[parent] == 1) {
          queue[queueEnd++] = parent;
        }
      }
    }
    queueStart = queueEndPrev;
  }

  free(nEdges);
  free(edgesOf);
  free(inDegree);
  free(queue);
  return result;
}
// @lc code=end
