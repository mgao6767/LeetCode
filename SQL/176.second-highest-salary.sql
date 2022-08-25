-- @lc app=leetcode id=176 lang=mysql
-- @lc code=start
-- SELECT CASE
--     WHEN min(salary) < max(salary) THEN min(salary)
--     ELSE NULL
--   END AS SecondHighestSalary
-- FROM (
--     SELECT DISTINCT salary
--     FROM Employee
--     ORDER BY salary DESC
--     LIMIT 2
--   ) AS tmp;
SELECT IFNULL(
    (
      SELECT DISTINCT Salary
      FROM Employee
      ORDER BY Salary DESC
      LIMIT 1 OFFSET 1
    ),
    NULL
  ) AS SecondHighestSalary;
-- @lc code=end