# Write your MySQL query statement below
select s1.name
from employee as s1,employee as s2
where s1.id=s2.managerId
group by s2.managerId
having count(*)>=5;