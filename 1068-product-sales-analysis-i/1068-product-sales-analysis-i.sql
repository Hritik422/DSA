# Write your MySQL query statement below
select Product.product_name,Sales.year,sales.price from Product 
right join Sales on Product.product_id=Sales.product_id;