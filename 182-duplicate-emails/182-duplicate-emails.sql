# Write your MySQL query statement below
#Self Join

SELECT DISTINCT P2.email AS Email
FROM Person P1 JOIN Person P2
ON P1.id <> P2.id AND P1.email = P2.email;