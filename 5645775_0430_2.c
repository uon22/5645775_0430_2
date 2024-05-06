#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
    return q->front == q->rear;
}

int is_full(QueueType* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("큐가 포화상태입니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("큐가 공백상태입니다.\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void display(QueueType* q) {
    int i;
    if (is_empty(q)) {
        printf("-------------------------------------\n");
        printf("현재 큐의 상태 : 큐가 비어있습니다.\n");
        printf("-------------------------------------\n");
        return;
    }
    printf("-------------------------------------\n");
    printf("현재 큐의 상태 : ");
    for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != (q->rear + 1) % MAX_QUEUE_SIZE; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("\n-------------------------------------\n");
}

int main() {
    QueueType q;
    int choice, value;
    init_queue(&q);

    while (1) {
        printf("\n1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요 : ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("큐에 삽입할 숫자를 입력하세요 : ");
            scanf_s("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            printf("큐에서 삭제된 원소 : %d\n", dequeue(&q));
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }

    return 0;
}