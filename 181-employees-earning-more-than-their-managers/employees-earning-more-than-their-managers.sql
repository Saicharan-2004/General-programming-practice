# Write your MySQL query statement below
select name as Employee
from Employee as e
where salary > (
    select salary
    from Employee as m
    where m.id=e.managerID
);