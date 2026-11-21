#include <stdio.h>
#define N 50

int st[N], top = -1;
int s_empty(void) { return top == -1; }
int s_full(void)  { return top == N - 1; }
int push(int x) { if (s_full()) { printf("Stack full\n"); return 0; } st[++top] = x; return 1; }
int pop(int *x) { if (s_empty()) { printf("Stack empty\n"); return 0; } *x = st[top--]; return 1; }

int q[N], head = 0, tail = 0, cnt = 0;
int q_empty(void) { return cnt == 0; }
int q_full(void)  { return cnt == N; }
int enqueue(int x) { if (q_full()) { printf("Queue full\n"); return 0; } q[tail] = x; tail = (tail + 1) % N; cnt++; return 1; }
int dequeue(int *x) { if (q_empty()) { printf("Queue empty\n"); return 0; } *x = q[head]; head = (head + 1) % N; cnt--; return 1; }
int q_size(void) { return cnt; }

void print_queue(void) {
    int n = q_size(), x;
    for (int i = 0; i < n; i++) { dequeue(&x); printf("%d ", x); enqueue(x); }
    printf("\n");
}

void reverse_queue(void) {
    int x;
    while (!q_empty()) { dequeue(&x); push(x); }
    while (!s_empty()) { pop(&x); enqueue(x); }
}

int main(void) {
    int x, k;
    char buf[4096], *p = buf;
    printf("Enter numbers: ");
    if (!fgets(buf, sizeof buf, stdin)) buf[0] = 0;
    while (sscanf(p, "%d%n", &x, &k) == 1) { enqueue(x); p += k; }
    if (q_empty()) {
        dequeue(&x);
        printf("Nothing entered\n");
        return 0;
    }
    printf("Before: "); print_queue();
    reverse_queue();
    printf("After:  "); print_queue();
    while (!q_empty()) dequeue(&x);
    dequeue(&x);
    return 0;
}
