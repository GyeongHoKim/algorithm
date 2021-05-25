from collections import deque

def solution(bridge_length, weight, truck_weights):
    arrived_trucks = deque([])
    driving_trucks = deque([])
    waiting_trucks = deque(truck_weights)
    time = 1
    truck = 0
    present_idx = 0
    prev_truck = truck_weights[present_idx]
    while len(arrived_trucks) < len(truck_weights):
        if waiting_trucks and truck + waiting_trucks[0] <= weight:
            truck += waiting_trucks.popleft()
            driving_trucks.append(0)
        time += 1
        idx = 0
        for _ in range(len(driving_trucks)):
            driving_trucks[idx] += 1
            if driving_trucks[idx] >= bridge_length:
                arrived_trucks.append(driving_trucks.popleft())
                truck -= prev_truck
                if present_idx + 1 < len(truck_weights):
                    present_idx += 1
                    prev_truck = truck_weights[present_idx]
            else:
                idx += 1
    return time