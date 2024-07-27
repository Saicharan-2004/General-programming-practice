# Write your MySQL query statement below
select employee_id,department_id
from Employee
where primary_flag = 'y'
group by employee_id 
union 
select employee_id,department_id
from employee
group by employee_id
having count(employee_id) = 1
-- having primary_flag = 'Y'