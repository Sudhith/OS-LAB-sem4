#include <stdio.h>

int main() {
    int n, time = 0, complete = 0;
    int bt[10], rt[10], at[10], pr[10];
    int wt[10], tat[10];
    int highest, min_pr;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Arrival time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        printf("Priority of P%d: ", i+1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];
    }

    while(complete != n) {
        min_pr = 9999;
        highest = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min_pr) {
                min_pr = pr[i];
                highest = i;
            }
        }

        if(highest == -1) {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0) {
            complete++;
            wt[highest] = time - bt[highest] - at[highest];
            if(wt[highest] < 0)
                wt[highest] = 0;
        }
    }

    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
