with data as (
    select car_id, start_date, end_date, "대여중"
    from car_rental_company_rental_history
    where '2022-10-16' between start_date and end_date
)


select a.car_id, if(b.대여중 = "대여중", "대여중", "대여 가능") as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY a left outer join data b on a.car_id = b.car_id
group by a.car_id
order by a.car_id desc