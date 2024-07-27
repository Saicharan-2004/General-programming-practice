# Write your MySQL query statement below
select round(count(distinct tab.player_id)/count(distinct act.player_id),2) as fraction
from activity as act
left join
(select player_id,min(event_date) as mini
from Activity
group by player_id) as tab
on act.player_id = tab.player_id
and datediff(act.event_date,tab.mini) = 1
