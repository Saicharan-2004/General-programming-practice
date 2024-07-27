# Write your MySQL query statement below
select product_id,year as first_year,quantity,price
from sales
where (product_id,year) in (select p.product_id,min(year)
from product as p
left join sales as s
on p.product_id = s.product_id
group by p.product_id)