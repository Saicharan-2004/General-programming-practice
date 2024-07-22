# Write your MySQL query statement below
select uni.unique_id,e.name
from employees as e 
left join employeeUNI as uni
on uni.id=e.id;