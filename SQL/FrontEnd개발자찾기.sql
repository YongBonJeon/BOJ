select ID, EMAIL, FIRST_NAME, LAST_NAME
from developers
where id in (
    select d.ID
    from developers d join skillcodes s
    where d.skill_code & s.code > 0 && s.category = "Front End"
    )
order by id
