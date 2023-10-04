#!/usr/bin/env python
# coding: utf-8

# In[1]:


def find_waiting_time(processes, n, burst_time, waiting_time):
    waiting_time[0] = 0
    
    for i in range(1, n):
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1]

def find_turnaround_time(processes, n, burst_time, waiting_time, turnaround_time):
    for i in range(n):
        turnaround_time[i] = burst_time[i] + waiting_time[i]

def find_average_times(processes, n, burst_time):
    waiting_time = [0] * n
    turnaround_time = [0] * n
    
    find_waiting_time(processes, n, burst_time, waiting_time)
    find_turnaround_time(processes, n, burst_time, waiting_time, turnaround_time)
    
    total_waiting_time = sum(waiting_time)
    total_turnaround_time = sum(turnaround_time)
    
    average_waiting_time = total_waiting_time / n
    average_turnaround_time = total_turnaround_time / n
    
    return waiting_time, turnaround_time, average_waiting_time, average_turnaround_time

def sjf_scheduling(processes, n, arrival_time, burst_time):
    completion_time = [0] * n
    remaining_time = burst_time.copy()
    current_time = 0
    total_processes = n
    
    while total_processes > 0:
        min_burst_time = float('inf')
        min_index = -1
        
        for i in range(n):
            if arrival_time[i] <= current_time and remaining_time[i] < min_burst_time and remaining_time[i] > 0:
                min_burst_time = remaining_time[i]
                min_index = i
        
        if min_index == -1:
            current_time += 1
        else:
            completion_time[min_index] = current_time + burst_time[min_index]
            current_time = completion_time[min_index]
            remaining_time[min_index] = 0
            total_processes -= 1
    
    return completion_time

def print_gantt_chart(processes, n, arrival_time, burst_time, completion_time):
    print("Gantt Chart:")
    print("-" * 50)
    
    current_time = 0
    for i in range(n):
        print(f"| P{processes[i]} ", end="")
        current_time = completion_time[i]
    
    print("|")
    print("-" * 50)

if __name__ == "__main__":
    n = int(input("Enter the number of processes: "))
    processes = [i + 1 for i in range(n)]
    arrival_time = []
    burst_time = []

    for i in range(n):
        arrival_time.append(int(input(f"Enter arrival time for P{i + 1}: ")))
        burst_time.append(int(input(f"Enter burst time for P{i + 1}: ")))

    completion_time = sjf_scheduling(processes, n, arrival_time, burst_time)
    waiting_time, turnaround_time, average_waiting_time, average_turnaround_time = find_average_times(processes, n, burst_time)

    print("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time")
    for i in range(n):
        print(f"P{processes[i]}\t{arrival_time[i]}\t\t{burst_time[i]}\t\t{completion_time[i]}\t\t{turnaround_time[i]}\t\t{waiting_time[i]}")

    print(f"\nAverage Waiting Time: {average_waiting_time}")
    print(f"Average Turnaround Time: {average_turnaround_time}")

    print_gantt_chart(processes, n, arrival_time, burst_time, completion_time)


# In[ ]:




