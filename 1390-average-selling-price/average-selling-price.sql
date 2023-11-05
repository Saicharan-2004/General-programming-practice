select p.product_id,round(sum(p.price*u.units)/sum(u.units),2) as average_price 
from Prices as p 
left join UnitsSold as u 
on p.product_id=u.product_id 
where u.purchase_date>=p.start_date and u.purchase_date<=p.end_date 
group by product_id
union
select p.product_id,0.00 as average_price
from Prices as p 
left join UnitsSold as u 
on p.product_id=u.product_id
where u.purchase_date is NULL 