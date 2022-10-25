# Write your MySQL query statement below
SELECT IFNULL(NULL,(SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1,1)) AS SecondHighestSalary;