#include <stdio.h>
int main() {
    int n, time = 0, complete = 0;
    int bt[10], rt[10], at[10];
    int wt[10], tat[10], min, shortest;
    int finish_time, check = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Arrival time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while(complete != n) {
        min = 9999;
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
                check = 1;
            }
        }

        if(check == 0) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0) {
            complete++;
            finish_time = time;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if(wt[shortest] < 0)
                wt[shortest] = 0;
        }
        check = 0;
    }

    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], wt[i], tat[i]);

    return 0;
}
