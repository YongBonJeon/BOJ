#with절 여러개 사용하는 법
with data as (
    select a.user_id, a.sales_date
    from online_sale a join user_info b on a.user_id = b.user_id
    where b.joined between '2021-01-01' and '2021-12-31'
    group by a.user_id, date_format(a.sales_date, '%Y-%m')
), alldata as (
    select count(user_id) as allcount
    from user_info
    where joined between '2021-01-01' and '2021-12-31'
)


select YEAR(sales_date) as YEAR, MONTH(sales_date) as MONTH, count(user_id) as PUCHASED_USERS, ROUND(count(user_id) / allcount, 1) as PUCHASED_RATIO
from data join alldata
group by DATE_FORMAT(sales_date, '%Y-%m')
order by YEAR, MONTH