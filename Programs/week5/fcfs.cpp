#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp) {
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}
void bubbleSort(int arr[], int time[], int priority[], int n) {
   int i, j;
   for (i = 0; i < n - 1; i++) {
       for (j = 0; j < n - i - 1; j++) {
           if (arr[j] > arr[j + 1]) {
               swap(&arr[j], &arr[j + 1]);
               swap(&time[j], &time[j + 1]);
               swap(&priority[j], &priority[j + 1]);
           }
       }
   }
}
void fcfs(int arr[], int time[], int priority[], int n) {
   bubbleSort(arr, time, priority, n);
   int i;
   int wait[n];
   int tottime = 0;
   int turn[n];
  // printf("Enter number of processes:\n");
   //printf("%d\n", n);
   printf("\n Burst Times:\n");
   for (i = 0; i < n; i++) {
       printf("P %d:", i+1);
       printf("%d\n", time[i]);
   }
   int total = 0;
   printf("\n Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
   for (i = 0; i < n; i++) {
       if (i == 0) {
           wait[i] = arr[i];
           tottime += time[i];
           turn[i] = time[i] - arr[i];
       } else {
           wait[i] = tottime - arr[i];
           tottime += time[i];
           turn[i] = tottime - arr[i];
       }
       total += turn[i];
       printf(" P%d \t\t %d \t\t %d \t\t \t%d\n", priority[i], time[i], wait[i], turn[i]);
   }
   float avgwait = (float)total / n;
   float avgburst = (float)total / n;
   printf("\nAverage Waiting Time=%f", avgwait);
   printf("\nAverage Turnaround Time=%f\n", avgburst);
}
int main() {	
   int arr[100], time[100], priority[100], n, i;
   printf("Enter the number of processes:\n");
   scanf("%d", &n);
   for (i = 0; i < n; i++) {
       printf("Arrival Time for process P%d: ", i);
       scanf("%d", &arr[i]);
       printf("Burst time for process P%d: ", i);
       scanf("%d", &time[i]);
       printf("Priority for process P%d: ", i);
       scanf("%d", &priority[i]);
   }
   fcfs(arr, time, priority, n);
}
