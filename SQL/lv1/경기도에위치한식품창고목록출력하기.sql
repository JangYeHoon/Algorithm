-- 코드를 입력하세요
SELECT warehouse_id, warehouse_name, address, nvl(freezer_yn, 'N')
from food_warehouse
where regexp_like(warehouse_name, '창고_경기+')