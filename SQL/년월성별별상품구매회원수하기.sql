with data as (
    select *
    from online_sale
    group by user_id, DATE_FORMAT(sales_date, '%Y-%m')
)

select year(sales_date) as year, month(sales_date) as month, gender, count(*) as users
from data a join user_info b on a.user_id = b.user_id
where gender is not null
group by gender, DATE_FORMAT(sales_date, '%Y-%m')
order by year, month, gender
