#include <stdio.h>
int main() {
    int a[20], b[20], x[20], i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;
 
    printf("Enter number of process:");
    scanf("%d", &n);
    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d:", i + 1);
        scanf("%d", &b[i]);
        a[i] = i + 1;
        x[i] = b[i];
    }
 
    for (i = 0; i < n; i++) {
        smallest = i;
        for (j = i + 1; j < n; j++) {
            if (b[j] < b[smallest]) {
                smallest = j;
            }
        }
        int temp = b[i];
        b[i] = b[smallest];
        b[smallest] = temp;
 
        temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
    }
 
    int wt[20];
    wt[0] = 0;
 
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += b[j];
        }
        avg += wt[i];
    }
 
    double avg_wt = avg / n;
    avg = 0;
 
    printf("\n Process \t Burst Time \t Waiting Time \t Turnaround Time");
    for (i = 0; i < n; i++) {
        int tat = b[i] + wt[i];
        printf("\n P%d \t\t %d \t\t %d \t\t \t%d", a[i], b[i], wt[i], tat);
        avg += tat;
    }
 
    double avg_tat = avg / n;
 
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f\n", avg_tat);
 
    return 0;
}
