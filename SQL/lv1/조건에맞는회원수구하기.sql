-- 코드를 입력하세요
SELECT count(*) as users
from user_info
where to_char(joined, 'YYYY') = '2021' and 20 <= age and age <= 29