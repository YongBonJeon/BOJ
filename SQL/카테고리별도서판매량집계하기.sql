with data as(
    select book_id, sum(sales) as sales
    from book_sales
    where DATE_FORMAT(sales_date, '%Y-%m') = '2022-01'
    group by book_id
)

select category, sum(sales) as TOTAL_SALES
from book a join data b on a.book_id = b.book_id
group by category
order by category