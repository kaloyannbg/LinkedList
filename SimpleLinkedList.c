#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SNode
{
    int data;           // <- current number
    struct SNode *next; // <- next element
};

typedef struct SNode t_node;

void insertNode(t_node **head, t_node **tail)
{
    t_node *tempHead = *head;
    t_node *tempTail = *tail;

    t_node *temp = (t_node *)malloc(sizeof(t_node));

    printf(" -- Enter Data (int) For Current Node: ");
    scanf("%d", &temp->data);

    temp->next = NULL;

    if (tempHead == NULL)
    {
        (*tail) = temp;
        (*head) = (*tail);
    }
    else
    {
        (*tail)->next = temp;
        (*tail) = temp;
    }
}

void printNodes(t_node *head)
{
    t_node *temp = head;

    if (temp == NULL)
    {
        printf(" -- Your head is empty -- \n");
        return;
    }

    printf("  ");

    while (temp != NULL)
    {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
}

void searchNode(t_node *head)
{
    if (head == NULL)
    {
        printf(" -- Sorry, but node is not initialized. ");
    }

    t_node *temp = head;

    int iSomeNum = 0, iPos = 0;

    printf(" -- Enter (int) Data you want to find: ");

    scanf("%d", &iSomeNum);

    while (temp != NULL)
    {
        if (temp->data == iSomeNum)
        {
            if (iPos == 0)
            {
                printf(" -- You find the number %d on head position [0] --\n", iSomeNum, iPos);
                return;
            }
            printf(" -- You find the number %d on position [%d] --\n", iSomeNum, iPos);
            return;
        }
        iPos++;
        temp = temp->next;
    }
    printf(" -- You didn\'t find the number: %d -- \n", iSomeNum);
}

void deleteNode(t_node **head, t_node **tail)
{

    t_node *myHead = *head;

    if (*head == NULL)
    {
        printf(" -- Sorry, but linked list did not have elements -- \n");
        return;
    }

    int iSomeNum = 0;

    printf(" -- Enter Data (int) For Delete Node: ");
    scanf("%d", &iSomeNum);
    // printf("\n\n --pass -- \n");

    if (myHead != NULL && myHead->data == iSomeNum)
    {
        *head = myHead->next;
        free(myHead);
        return;
    }

    while (myHead->next != NULL)
    {

        if (myHead->next->data == iSomeNum)
        {

            t_node *temp = myHead->next;

            if (temp->next != NULL) // If element is not last
            {
                myHead->next = myHead->next->next;
            }
            else if (temp->next == NULL) // if element is last
            {
                (*tail) = myHead;     // new last element tail
                (*tail)->next = NULL; // next element in last element is NULL
            }

            free(temp);
            return;
        }

        myHead = myHead->next;
    }
}

int main(int argc, char const *argv[])
{
    t_node *head = NULL;
    t_node *tail = NULL;

    for (int i = 0; i < 5; i++)
    {
        insertNode(&head, &tail);
    }

    printNodes(head);

    // searchNode(head);

    deleteNode(&head, &tail);

    printNodes(head);

    return 0;
}
