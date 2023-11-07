#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
 
void *even(void *param)
{
        int *arr = (int *)param;
        int size = arr[0];
        int *sum = malloc(sizeof(int));
        *sum = 0;
        for (int i = 1; i <= size; i++)
                if (arr[i] % 2 == 0)
                        *sum += arr[i];
        return sum;
}
 
void *odd(void *param)
{
        int *arr = (int *)param;
        int size = arr[0];
        int *sum = malloc(sizeof(int));
        *sum = 0;
        for (int i = 1; i <= size; i++)
                if (arr[i] % 2 != 0)
                        *sum += arr[i];
        return sum;
}
 
int main()
{
        int n, evenSum, oddSum;
        printf("No. of Elements: \n");
        scanf("%d", &n);
        int *arr = malloc((n + 1) * sizeof(int));
        arr[0] = n;
        printf("Elements:\n");
 
        for (int i = 1; i <= n; i++)
                scanf("%d", &arr[i]);
 
        pthread_t t1, t2;
        pthread_create(&t1, NULL, even, (void *)arr);
        pthread_create(&t2, NULL, odd, (void *)arr);
 
        int *result;
        pthread_join(t1, (void **)&result);
        evenSum = *result;
        free(result);
 
        pthread_join(t2, (void **)&result);
        oddSum = *result;
        free(result);
 
        printf("EvenSum: %d\n", evenSum);
        printf("OddSum: %d\n", oddSum);
 
        free(arr);
 
        return 0;
}
