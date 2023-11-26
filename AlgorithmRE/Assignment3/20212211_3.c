#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int amount, tries;

    printf("n: ");
    scanf("%d", &amount);
    printf("m: ");
    scanf("%d", &tries);

    srand(0);

    for (int tryCount = 0; tryCount < tries; tryCount++) {
        Node* randomList = NULL;

        // 임의의 값으로 정수를 생성. 정수들은 n개의 연결리스트로 구성 
        for (int amountCount = 0; amountCount < amount; amountCount++) {
            Node* newList = (Node*)malloc(sizeof(Node));
            newList->data = rand() % 10000;
            newList->next = randomList;
            randomList = newList;
        }
        //정렬되지 않은 상태를 먼저 출력한다. 
        printf("Before: ");
        Node* current = randomList;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");

		//head포인터 배열과, tail포인터 배열을 생성 
        Node* head[10] = {NULL};
        Node* tail[10] = {NULL};

		//1의 자리 , 10의 자리, 100의 자리, 1000의 자리 순서로 정렬을 한다. 
        int div = 1;
        for (int i = 0; i < 4; i++) {
            Node* current = randomList;
			//헤드에 연결리스트를 순서대로 생성한 다음 마지막을 tail로 연결 
            while (current != NULL) {
                int test = (current->data / div) % 10;

                if (head[test] == NULL) {
                    head[test] = current;
                    tail[test] = current;
                } else {
                    tail[test]->next = current;
                    tail[test] = current;
                }

                current = current->next;
            }
			//정렬된 리스트를 다시 randomList로 이동시킨뒤 자리수를 바꾸어 다시 정렬 
			randomList = NULL;
			Node* tailList = NULL;
			for (int j = 0; j < 10; j++) {
		    	if (head[j] != NULL) {
		        	if (randomList == NULL) {
		            	randomList = head[j];
		        	} else {
		            	tailList->next = head[j];
		        	}
		        	tailList = tail[j];
		        	head[j] = tail[j] = NULL;
		    	}
			}
			if (tailList != NULL) {
		    	tailList->next = NULL;
			}
            div *= 10;
        }
		//정렬된 데이터를 출력한다. 
        printf("After: ");
        current = randomList;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");

		//동적할당 free 
        Node* temp;
        while (randomList != NULL) {
            temp = randomList;
            randomList = randomList->next;
            free(temp);
        }
        printf("\n");
    }

    return 0;
}

