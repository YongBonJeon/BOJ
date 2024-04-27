with data as(
select category, MAX(price) as MAX_PRICE
from food_product
where category = '과자' or category = '국' or category = '김치' or category = '식용유'
group by category
order by MAX_PRICE desc
    )

select a.category, b.MAX_PRICE, a.PRODUCT_NAME
from food_product a join data b on (a.category = b.category and a.price = b.MAX_PRICE)
order by b.MAX_PRICE desc