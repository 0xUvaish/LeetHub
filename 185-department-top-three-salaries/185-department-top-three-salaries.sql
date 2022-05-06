# Write your MySQL query statement below



SELECT D.name AS Department, E1.name AS Employee, E1.salary AS Salary
FROM Employee AS E1, Department AS D
WHERE
(
    SELECT COUNT(DISTINCT E2.salary)
    FROM Employee AS E2
    WHERE E2.departmentId = E1.departmentId AND E2.salary > E1.salary
) < 3
AND E1.departmentId = D.id;