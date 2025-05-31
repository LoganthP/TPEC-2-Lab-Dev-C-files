#include <stdio.h>
#include <stdlib.h>
struct slinklist {
    int data;
    struct slinklist *next;
};
typedef struct slinklist node;
node *start = NULL;
int menu() {
    int ch;
    printf("\n 1.Create a list ");
    printf("\n 2.Insert a node at specified position");
    printf("\n 3.Display");
    printf("\n 4. Exit ");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
node* getnode() {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}
void createlist(int n) {
    int i;
    node *newnode;
    node *temp;
    for (i = 0; i < n; i++) {
        newnode = getnode();
        if (start == NULL) {
            start = newnode;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

int countnode(node *ptr) {
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void display() {
    node *temp;
    temp = start;
    printf("\n The contents of List (Left to Right): \n");
    if (start == NULL) {
        printf("\n Empty List");
        return;
    } else {
        while (temp != NULL) {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
    }
    printf(" X ");
}

void insert_at_pos() {
    node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = getnode();
    printf("\n Enter the position: ");
    scanf("%d", &pos);
    nodectr = countnode(start);

    if (pos < 1 || pos > nodectr + 1) {
        printf("Position %d is invalid\n", pos);
        free(newnode);
        return;
    }

    if (pos == 1) {
        newnode->next = start;
        start = newnode;
    } else {
        temp = start;
        while (ctr < pos - 1) {
            temp = temp->next;
            ctr++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main() 
{
    int ch, n;
    while (1) 
	{
        ch = menu();
        switch (ch) 
		{
            case 1:
                if (start == NULL) 
				{
                    printf("\n Number of nodes you want to create: ");
                    scanf("%d", &n);
                    createlist(n);
                    printf("\n List created..");
                } 
				else
                    printf("\n List is already created..");
                break;
            case 2:
                insert_at_pos();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
}
