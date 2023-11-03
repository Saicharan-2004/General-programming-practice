# Write your MySQL query statement below
select alias2.user_id as user_id,round(alias2.confirmed/alias2.total,2) as confirmation_rate
from
(
    select alias.user_id as user_id,alias.qw as confirmed,alias.qr as timeout,(alias.qw+alias.qr) as total
    from
    (
        select s.user_id, sum(action= 'confirmed' ) as qw,sum(action= 'timeout' ) as qr
        from signups as s
        left join confirmations as c
        on s.user_id=c.user_id
        group by s.user_id
    ) as alias
) as alias2
where confirmed is not null
union
select alias2.user_id as user_id,0.00 as confirmation_rate
from
(
    select alias.user_id as user_id,alias.qw as confirmed,alias.qr as timeout,(alias.qw+alias.qr) as total
    from
    (
        select s.user_id, sum(action= 'confirmed' ) as qw,sum(action= 'timeout' ) as qr
        from signups as s
        left join confirmations as c
        on s.user_id=c.user_id
        group by s.user_id
    ) as alias
) as alias2
where alias2.confirmed is NULL;