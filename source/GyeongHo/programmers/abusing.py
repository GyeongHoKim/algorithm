def solution(id_list, report, k):
    mail = dict()
    reporting = dict()
    reported = dict()
    abused = dict()
    result = []
    for _id in id_list:
        reporting[_id] = []
    for case in report:
        _from, _to = case.split()
        if _to in reporting[_from]:
            continue
        reporting[_from].append(_to)
        reported[_to] = reported.get(_to, 0) + 1
    for _id in id_list:
        abused[_id] = False
        mail[_id] = 0
    for key in reported:
        if reported[key] >= k:
            abused[key] = True
    for key in reporting:
        for name in reporting[key]:
            if abused[name]:
                mail[key] = mail.get(key, 0) + 1
    for _id in id_list:
        result.append(mail[_id])
    return result

print(solution(["con", "ryan"], ["ryan con", "ryan con", "ryan con", "ryan con"], 3))