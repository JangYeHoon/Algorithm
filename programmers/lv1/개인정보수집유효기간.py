from datetime import datetime, timedelta
from dateutil.relativedelta import relativedelta

def get_date(date):
    return datetime.strptime(date, "%Y.%m.%d")

def solution(today, terms, privacies):
    today = get_date(today)
    answer = []
    tm = {}

    for t in terms:
        term, mon = t.split(" ")
        tm[term] = int(mon)

    for i, p in enumerate(privacies):
        date, term = p.split(" ")
        time = tm[term]
        start_date = get_date(date)
        end_date = start_date + relativedelta(months=time)

        if end_date <= today:
            answer.append(i+1)


    return answer