# Write your MySQL query statement below
#Self Join
#Correlated Subqueries

SELECT E1.name AS Employee 
FROM Employee E1 JOIN Employee E2 
ON E1.managerId =  E2.id AND E1.salary > E2.salary;
