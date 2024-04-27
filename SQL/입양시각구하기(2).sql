with hours as (
    select 0 as hour , 0 as count
union
select 1, 0
union
select 2, 0
union
select 3, 0
union
select 4, 0
union
select 5, 0
union
select 6, 0
union
select 7, 0
union
select 8, 0
union
select 9, 0
union
select 10, 0
union
select 11, 0
union
select 12, 0
union
select 13, 0
union
select 14, 0
union
select 15, 0
union
select 16, 0
union
select 17, 0
union
select 18, 0
union
select 19, 0
union
select 20, 0
union
select 21, 0
union
select 22, 0
union
select 23, 0
    )

select hour, sum(count) as count
from (
    select hour(datetime) as hour, count(*) as count
    from animal_outs
    group by hour(datetime)
    union all
    select *
    from hours
    ) t
group by hour
order by hour

