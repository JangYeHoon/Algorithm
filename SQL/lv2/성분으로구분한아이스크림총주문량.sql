-- 코드를 입력하세요
SELECT icecream_info.ingredient_type, sum(total_order)
from first_half inner join icecream_info on first_half.flavor = icecream_info.flavor
group by ingredient_type