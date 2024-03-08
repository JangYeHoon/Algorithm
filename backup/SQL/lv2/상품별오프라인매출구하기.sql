-- 코드를 입력하세요
SELECT product.product_code, SUM(offline_sale.sales_amount * product.price) as sales
from product inner join offline_sale on product.product_id = offline_sale.product_id
group by product.product_code
order by sales desc, product_code