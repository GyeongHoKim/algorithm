import math

def solution(fees, records):
    answer = []
    accDiff = dict()
    parkingLot = dict()
    for instr in records:
        time, tmp, pos = instr.split()
        car = int(tmp)
        if pos == "IN":
            parkingLot[car] = time
        if pos == "OUT":
            inTime, outTime = parkingLot[car], time
            diffTime = (int(outTime[0:2]) - int(inTime[0:2])) * 60 + int(outTime[3:]) - int(inTime[3:])
            accDiff[car] = accDiff.get(car, 0) + diffTime
            parkingLot.pop(car)
    if len(parkingLot) > 0:
        for key in parkingLot:
            inTime, outTime = parkingLot[key], "23:59"
            diffTime = (int(outTime[0:2]) - int(inTime[0:2])) * 60 + int(outTime[3:]) - int(inTime[3:])
            accDiff[key] = accDiff.get(key, 0) + diffTime
    for key in accDiff:
        cost = fees[1] + (math.ceil((accDiff[key] - fees[0]) / fees[2]) * fees[3] if accDiff[key] > fees[0] else 0)
        accDiff[key] = cost
    sortedCost = sorted(accDiff.items(), key = lambda x: int(x[0]))
    for i in sortedCost:
        answer.append(i[1])
    return answer

print(solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))