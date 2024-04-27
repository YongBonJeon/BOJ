with fecode as (
    select sum(code) as fecode
    from skillcodes
    where category = 'front end'
    ), pycode as (
    select code as pycode
    from skillcodes
    where name = 'python'
    ), cscode as (
    select code as cscode
    from skillcodes
    where name = 'c#'
    ), data as (
select case
        when skill_code & fecode > 0 && skill_code & pycode > 0 then 'A'
        when skill_code & cscode > 0 then 'B'
        when skill_code & fecode > 0 then 'C'
        end as GRADE, ID, EMAIL
from developers, fecode, pycode, cscode
)

select *
from data
where grade is not null
order by grade, id