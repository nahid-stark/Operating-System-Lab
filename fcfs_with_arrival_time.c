#include <stdio.h>
#include <string.h>

struct Process {
    char id[20];
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

void averageWaitingTime(struct Process processes[], int n) {
    int sum = 0;
    float result = 0;
    for(int i=0; i<n; i++) {
        sum = sum + processes[i].waitingTime;
    }
    result = (float) sum / n;
    printf("\nAverage Waiting Time : %.2f", result); 
}

void averageCompletionTime(struct Process processes[], int n) {
    int sum = 0;
    float result = 0;
    for(int i=0; i<n; i++) {
        sum = sum + processes[i].completionTime;
    }
    result = (float) sum / n;
    printf("\nAverage Completion Time : %.2f", result); 
}

void averageTurnaroundTime(struct Process processes[], int n) {
    int sum = 0;
    float result = 0;
    for(int i=0; i<n; i++) {
        sum = sum + processes[i].turnaroundTime;
    }
    result = (float) sum / n;
    printf("\nAverage TurnAround Time : %.2f", result); 
}

int main() {
    int n;
    printf("Enter Number of Process : ");
    scanf("%d", &n);
    fflush(stdin);
    struct Process processes[n];
    struct Process temp[n];
    for(int i=0; i<n; i++) {
        printf("\nEnter Process Id : ");
        fgets(processes[i].id, sizeof(processes[i].id), stdin);
        printf("Enter Process Arrival Time : ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter Burst Time : ");
        scanf("%d", &processes[i].burstTime);
        fflush(stdin);
    }
    for (int i = 0; i < n; i++) {
        temp[i] = processes[i];
    }
    sort(processes, n);
    calculate(processes, n);
    printf("\nProcess ID   Arrival Time   Burst Time   Completion Time   Waiting Time   Turnaround Time\n");
    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            if((strcmp(temp[j].id, processes[i].id)) == 0) {
                printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
            }
        }
    }
    averageWaitingTime(processes, n);
    averageCompletionTime(processes, n);
    averageTurnaroundTime(processes, n);
    return 0;
}
