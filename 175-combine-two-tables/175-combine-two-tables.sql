# Write your MySQL query statement below

#Using Left Join
# SELECT firstName, lastName, city, state 
# FROM Person LEFT JOIN Address ON Person.personId = Address.personId; 

#Using Right Join
SELECT firstName, lastName, city, state 
FROM Address RIGHT JOIN Person ON Person.personId = Address.personId; 