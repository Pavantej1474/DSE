#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int p;
    int at;
    int bt;
    int rbt;
    int wt;
    int tat;
    int ct;
} P;

void calcSJF(P *p, int n)
{
    int cur = 0;
    int comp = 0;
    int totalW = 0;
    int totalT = 0;

    while (comp < n)
    {
        int shortest = INT_MAX;
        int shortestIndex = -1;

        for (int i = 0; i < n; i++)
        
        {
            if (p[i].at <= cur && p[i].rbt < shortest && p[i].rbt > 0)
            {
                shortest = p[i].rbt;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1)
        {
            cur++;
            continue;
        }

        p[shortestIndex].rbt--;
        cur++;

        if (p[shortestIndex].rbt == 0)
        {
            comp++;
            p[shortestIndex].ct = cur;
            p[shortestIndex].tat = p[shortestIndex].ct - p[shortestIndex].at;
            p[shortestIndex].wt = p[shortestIndex].tat - p[shortestIndex].bt;
            totalW += p[shortestIndex].wt;
            totalT += p[shortestIndex].tat;
        }
    }

    printf("P\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].p, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    float avgW = (float)totalW / n;
    float avgT = (float)totalT / n;

    printf("\nAWT: %.2f\n", avgW);
    printf("ATAT: %.2f\n", avgT);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    P *p = (P *)malloc(n * sizeof(P));

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].p = i + 1;
        p[i].rbt = p[i].bt;
    }

    calcSJF(p, n);

    free(p);
    return 0;
}
