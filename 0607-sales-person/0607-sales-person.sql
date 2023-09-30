
(select s.name 
from SalesPerson as s
where (
    s.name not in (select s.name from SalesPerson as s, Company as c, Orders as o where s.sales_id = o.sales_id and c.com_id = o.com_id and c.name = 'RED')
));