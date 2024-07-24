# Write your MySQL query statement below
select query_name,round(avg(rating/position),2) as quality,round(100*sum(if(rating<3,1,0))/count(*),2) as poor_query_percentage
from Queries q
where query_name is not null
group by query_name