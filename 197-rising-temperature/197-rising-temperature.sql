# Write your MySQL query statement below

SELECT W1.id FROM Weather W1, Weather W2
WHERE
    W1.temperature > W2.temperature AND 
    DATEDIFF(w1.RecordDate, w2.RecordDate)=1;