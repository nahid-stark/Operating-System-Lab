#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void sort(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculate(struct Process processes[], int n) {
    int realTime = 0;
    for(int i=0; i<n; i++) {
        if(realTime < processes[i].arrivalTime) {
            realTime = processes[i].arrivalTime;
        }
        processes[i].completionTime = realTime + processes[i].burstTime;
        realTime = processes[i].completionTime;
    }
    for(int i=0; i<n; i++) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
    }
    for(int i=0; i<n; i++) {
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

int main() {
    int n;
    printf("Enter Number of Process : ");
    scanf("%d", &n);
    struct Process processes[n];
    struct Process temp[n];
    for(int i=0; i<n; i++) {
        printf("\nEnter Process Id : ");
        scanf("%d", &processes[i].id);
        printf("Enter Process Arrival Time : ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter Burst Time : ");
        scanf("%d", &processes[i].burstTime);
    }
    for (int i = 0; i < n; i++) {
        temp[i] = processes[i];
    }
    sort(processes, n);
    calculate(processes, n);
    printf("\nProcess ID   Arrival Time   Burst Time   Completion Time   Waiting Time   Turnaround Time\n");
    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            if(temp[j].id == processes[i].id) {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
            }
        }
    }
    return 0;
}
