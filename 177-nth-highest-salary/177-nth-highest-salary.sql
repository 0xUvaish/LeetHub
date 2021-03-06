CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE x INT DEFAULT N-1;
  RETURN (
            SELECT IFNULL((SELECT DISTINCT E1.salary FROM Employee E1 WHERE x = (SELECT COUNT(DISTINCT E2.salary) FROM Employee E2 WHERE E2.salary>E1.salary)), NULL)
  );
END

# Method 1 - Limit & Offset
# SELECT IFNULL((SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET x), NULL)
# Method 2 - Correlated Subqueries
