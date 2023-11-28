#include <stdio.h>

#define MAX_SIZE 6

int main() {
    int n = MAX_SIZE;
    int arr[MAX_SIZE];
    int front = 0;
    int back = 0;

    while (1) { // In C, we use 1 for true
        int x;
        scanf("%d", &x);

        if (x == 4) {
            break;
        } else if (x == 1) {
            int y;
            scanf("%d", &y);
            if ((back + 1) % n == front) {
                printf("Queue Overflow\n");
            } else {
                arr[back] = y;
                back = (back + 1) % n;
            }
        } else if (x == 2) {
            if (back == front) {
                printf("Queue Underflow\n");
            } else {
                front = (front + 1) % n;
            }
        } else if (x == 3) {
            int i = front;
            int count = (back - front + n) % n;
            if(count==0){
                printf("NULL");
            }
            else{
            for (int j = 0; j < count; j++) {
                printf("%d ", arr[i]);
                i = (i + 1) % n;
            }}
            printf("\n");
        }
    }

    return 0;
}
