select a.product_code, sum(b.sales_amount) * a.price as SALES
from product a join offline_sale b on a.product_id = b.product_id
group by a.product_id
order by sales desc, product_code