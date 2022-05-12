# Write your MySQL query statement below
#Correlated Subquerry

SELECT score, (SELECT COUNT(DISTINCT B.score) FROM Scores B WHERE B.score > A.score)+1 AS 'rank'
FROM Scores A
ORDER BY score DESC