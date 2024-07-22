# Write your MySQL query statement below
select distinct w1.id
from Weather as w1
left join Weather as w2
on DATEDIFF(w1.recordDate,w2.recordDate) = 1
where w1.temperature > w2.temperature;
-- where DATEDIFF(w1.recordDate,w2.recordDate) = 1 and w1.temperature > w2.temperature