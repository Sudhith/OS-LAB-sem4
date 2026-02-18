#include <stdio.h>
int main() {
    int n, i, ctime = 0, tq;
    int bt[10], rt[10], wt[10] = {0}, tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int done;
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;
                if(rt[i] > tq) {
                    ctime += tq;
                    rt[i] -= tq;
                } else {
                    ctime += rt[i];
                    wt[i] = ctime - bt[i]; //WT = CT - BT
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}


