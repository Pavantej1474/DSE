#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int rem_time;
    int priority;
    int start_time;
    int completion_time;
} Process;
 
void sort_by_arrival_time(Process* processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
 
void roundRobin(Process* processes, int n, int time_slice) {
    int timer = 0;
    int done = 0;
    int quantum = time_slice;
    float total_tat = 0, total_wt = 0;
    printf("\n Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
    while (done != n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].rem_time > 0 && processes[i].arrival_time <= timer) {
                if (processes[i].rem_time > quantum) {
                    timer += quantum;
                    processes[i].rem_time -= quantum;
                } else {
                    timer += processes[i].rem_time;
                    processes[i].rem_time = 0;
                    processes[i].completion_time = timer;
                    done++;
                }
                printf(" P%d \t\t %d \t\t %d \t\t \t%d\n", processes[i].pid, processes[i].burst_time, 
                       processes[i].completion_time - processes[i].burst_time - processes[i].arrival_time, 
                       processes[i].completion_time - processes[i].arrival_time);
            }
        }
    }
}
 
int main() {
    int n, time_slice;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process* processes = (Process*)malloc(n * sizeof(Process));
    printf("Enter PID, Arrival Time, Burst Time, Priority\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d :", i + 1);
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].rem_time = processes[i].burst_time;
        processes[i].start_time = 0;
        processes[i].completion_time = 0;
    }
    printf("Enter Time Slice: ");
    scanf("%d", &time_slice);
    sort_by_arrival_time(processes, n);
    roundRobin(processes, n, time_slice);
    free(processes);
    return 0;
}
