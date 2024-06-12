#include <stdio.h>
#include <stdlib.h>


typedef struct list {
    int val;
    struct list *next;
} data;

typedef struct queue {
    data *head;
    data *tail;
} qyu;

void init(qyu *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

void add(qyu *queue, int val) {
    data *baru = (data *)malloc(sizeof(data));
    baru->val = val;
    baru->next = NULL;
    
    if (queue->tail == NULL) {
        queue->head = baru;
        queue->tail = baru;
    } else {
        queue->tail->next = baru;
        queue->tail = baru;
    }
}

void swapVal(qyu *queue, int position){
    int len = 0;
    data *curr = queue->head;
    while (curr!=NULL)
    {
        len++;
        curr = curr->next;
    }
    data *left = queue->head;
    int i=1;
    while (i<position)
    {
        left = left->next;
        i++;
    }
    
    data *right = queue->head;
    for (i = 1; i <= len-position; i++){
        right = right->next;
    }
    int temp = left->val;
    left->val = right->val;
    right->val = temp; 
}

void display(data *head) {

    if (head == NULL) {
        printf("stderr: The list is empty!\n");
        return;
    }
    data *tmp = head;

    printf("\n");
    while (tmp != NULL) {
        if (tmp->val != -1) {
            printf("%d ", tmp->val);
        }
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    qyu queue;
    init(&queue);
    int val, position;
    while (1) {
        scanf("%d", &val);
        if (val == -1) {
            break;
        }
        add(&queue, val);
    }
    getchar();
    scanf("%d", &position);
    swapVal(&queue, position);
    display(queue.head);
    return 0;
}
