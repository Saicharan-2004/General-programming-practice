# Write your MySQL query statement below
select contest_id, round(100*count(distinct r.user_id)/count(distinct u.user_id),2) as percentage
from Users u
cross join Register r
group by contest_id
order by percentage desc,contest_id asc