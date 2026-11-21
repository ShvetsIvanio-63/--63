#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct Node { int val; struct Node *next; } Node;

Node *top = NULL;
int s_empty(void) { return top == NULL; }
int s_full(void)  { return 0; }
int push(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) { printf("Stack full\n"); return 0; }
    n->val = x; n->next = top; top = n; return 1;
}
int pop(int *x) {
    if (s_empty()) { printf("Stack empty\n"); return 0; }
    Node *n = top; *x = n->val; top = n->next; free(n); return 1;
}

Node *head = NULL, *tail = NULL;
int cnt = 0;
int q_empty(void) { return head == NULL; }
int q_full(void)  { return cnt == N; }
int enqueue(int x) {
    if (q_full()) { printf("Queue full\n"); return 0; }
    Node *n = malloc(sizeof(Node));
    if (!n) { printf("Queue full\n"); return 0; }
    n->val = x; n->next = NULL;
    if (tail) tail->next = n; else head = n;
    tail = n; cnt++; return 1;
}
int dequeue(int *x) {
    if (q_empty()) { printf("Queue empty\n"); return 0; }
    Node *n = head; *x = n->val; head = n->next;
    if (!head) tail = NULL;
    free(n); cnt--; return 1;
}
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