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

        // ������ ������ ������ ����. �������� n���� ���Ḯ��Ʈ�� ���� 
        for (int amountCount = 0; amountCount < amount; amountCount++) {
            Node* newList = (Node*)malloc(sizeof(Node));
            newList->data = rand() % 10000;
            newList->next = randomList;
            randomList = newList;
        }
        //���ĵ��� ���� ���¸� ���� ����Ѵ�. 
        printf("Before: ");
        Node* current = randomList;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");

		//head������ �迭��, tail������ �迭�� ���� 
        Node* head[10] = {NULL};
        Node* tail[10] = {NULL};

		//1�� �ڸ� , 10�� �ڸ�, 100�� �ڸ�, 1000�� �ڸ� ������ ������ �Ѵ�. 
        int div = 1;
        for (int i = 0; i < 4; i++) {
            Node* current = randomList;
			//��忡 ���Ḯ��Ʈ�� ������� ������ ���� �������� tail�� ���� 
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
			//���ĵ� ����Ʈ�� �ٽ� randomList�� �̵���Ų�� �ڸ����� �ٲپ� �ٽ� ���� 
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
		//���ĵ� �����͸� ����Ѵ�. 
        printf("After: ");
        current = randomList;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");

		//�����Ҵ� free 
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

