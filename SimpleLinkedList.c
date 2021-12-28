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

    printf("\n");

    while (temp != NULL)
    {
        printf("%-7d -> %d \n", temp->data, &temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void searchNode(t_node *head)
{

    printNodes(head);

    if (head == NULL)
    {
        printf(" -- Sorry, but node is not initialized. -- \n");
        return;
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

void freeNodes(t_node *head)
{
    t_node *temp = head;

    if (temp == NULL)
    {
        printf("\n -- Do not have Nodes for clean up. --\n\n");
        return;
    }

    while (temp != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
    printf("\n -- Sucesfully clean up the nodes! -- \n\n");
}

int main(int argc, char const *argv[])
{
    t_node *head = NULL;
    t_node *tail = NULL;

    int iChoice = -1;

    while (iChoice != 0)
    {
        system("clear");
        printf("1. Print nodes. \n");
        printf("2. Insert node. \n");
        printf("3. Search node. \n");
        printf("4. Delete node. \n\n");

        printf(" -- Enter your choice: ");
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printNodes(head);
            break;
        case 2:
            insertNode(&head, &tail);
            break;
        case 3:
            searchNode(head);
            break;
        case 4:
            deleteNode(&head, &tail);
            break;
        case 0:
            printf("\n -- Bye! -- \n");
            break;
        default:
            printf("\n -- Invalid choice! -- \n");
            break;
        }
        if (iChoice != 0)
        {
            system("pause");
        }
    }

    freeNodes(head);

    return 0;
}
