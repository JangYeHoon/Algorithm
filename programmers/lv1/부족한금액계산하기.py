# https://school.programmers.co.kr/learn/courses/30/lessons/82612

def solution(price, money, count):
    total_price = price
    for i in range(2, count + 1):
        total_price += price * i
    if total_price < money:
        return 0
    return total_price - money