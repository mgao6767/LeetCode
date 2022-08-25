-- @lc app=leetcode id=178 lang=mysql
-- @lc code=start
SELECT score,
  DENSE_RANK() OVER(
    ORDER BY score DESC
  ) AS "rank"
FROM Scores;
-- @lc code=end