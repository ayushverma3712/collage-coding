#include <stdio.h>
#include <stdlib.h>
struct snode
{
    int data;
    struct snode *node;
};
struct snode *insertatbeg(struct snode *head)
{
    struct snode *temp = (struct snode *)malloc(sizeof(struct snode));
    if (temp == NULL)
    {
        printf("Space not available\n");
    }
    else
    {
        printf("Enter the data = ");
        scanf("%d", &temp->data);
        temp->node = head;
        head = temp;
    }
    return head;
}
void display_LL(struct snode *head)
{
    struct snode *p1 = head;
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        while (p1)
        {
            printf("%d ", p1->data);
            p1 = p1->node;
        }
        printf("\n");
    }
}
struct snode *insertatlast(struct snode *head)
{
    struct snode *temp = (struct snode *)malloc(sizeof(struct snode));
    struct snode *p1;
    if (temp == NULL)
    {
        printf("Space not available\n");
    }
    else if (head == NULL)
    {
        printf("Enter the data = ");
        scanf("%d", &temp->data);
        temp->node = NULL;
        head = temp;
    }
    else
    {
        p1 = head;
        printf("Enter the data = ");
        scanf("%d", &temp->data);
        while (p1->node != NULL)
        {
            p1 = p1->node;
        }
        p1->node = temp;
        temp->node = NULL;
    }
    return head;
}
struct snode *insertatpos_after(struct snode *head)
{
    int item;
    printf("Enter the item = ");
    scanf("%d", &item);
    struct snode *temp = (struct snode *)malloc(sizeof(struct snode));
    struct snode *p1;

    if (temp == NULL)
    {
        printf("Space is not available\n");
    }
    else
    {
        printf("Enter the data = ");
        scanf("%d", &temp->data);
        p1 = head;
        while (p1 != NULL && p1->data != item)
        {
            p1 = p1->node;
        }
        if (p1 != NULL)
        {
            temp->node = p1->node;
            p1->node = temp;
        }
        else
        {
            printf("Item not found\n");
            free(temp);
        }
    }
    return head;
}
struct snode *insertatpos_before(struct snode *head)
{
    int item;
    printf("Enter the item = ");
    scanf("%d", &item);
    struct snode *temp = (struct snode *)malloc(sizeof(struct snode));
    struct snode *p1, *p2;

    if (temp == NULL)
    {
        printf("Space is not available\n");
    }
    else
    {
        printf("Enter your data = ");
        scanf("%d", &temp->data);
        p1 = head;
        p2 = NULL;
        while (p1 != NULL && p1->data != item)
        {
            p2 = p1;
            p1 = p1->node;
        }
        if (p1 != NULL)
        {
            temp->node = p1;
            if (p2 != NULL)
            {
                p2->node = temp;
            }
            else
            {
                head = temp; // Insert at beginning
            }
        }
        else
        {
            printf("Item not found\n");
            free(temp);
        }
    }
    return head;
}
struct snode *begindelete(struct snode *head)
{
    struct snode *p1 = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Deleted Item = %d\n", head->data);
        head = head->node;
        free(p1);
    }
    return head;
}
struct snode *lastdelete(struct snode *head)
{
    struct snode *p1 = head, *p2;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->node == NULL)
    {
        printf("Deleted item = %d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        while (p1->node != NULL)
        {
            p2 = p1;
            p1 = p1->node;
        }
        printf("Deleted item = %d\n", p1->data);
        p2->node = NULL;
        free(p1);
    }
    return head;
}
struct snode *deletepos(struct snode *head)
{
    struct snode *p1 = head, *p2 = NULL;
    int pos, count = 1;
    printf("Enter the position = ");
    scanf("%d", &pos);
    while (p1 != NULL)
    {
        p1 = p1->node;
        count++;
    }
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (count < pos)
    {
        printf("Deletion cannot be possible\n");
    }
    else
    {
        p1 = head;
        count = 1;
        while (count < pos)
        {
            p2 = p1;
            p1 = p1->node;
            count++;
        }
        if (p2 != NULL)
        {
            p2->node = p1->node;
        }
        else
        {
            head = p1->node; // Deleting the head
        }
        printf("Deleted Item = %d\n", p1->data);
        free(p1);
    }
    return head;
}
void recursion_reverse_display(struct snode *head)
{
    if (head == NULL)
    {
        return;
    }
    recursion_reverse_display(head->node);
    printf("%d ", head->data);
}
struct snode *reverse_list(struct snode *head)
{
    struct snode *p1 = NULL, *p2 = head, *p3 = NULL;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (p2 != NULL)
        {
            p3 = p2->node;
            p2->node = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
    return head;
}
int main()
{
    int choice;
    struct snode *head = NULL;
    do
    {
        printf("Enter your choice \n 1.insertatbeg\n2.insertatlast\n3.insertatpos_after\n4.insertatpos_before\n5.begindelete\n6.lastdelete\n7.deletepos\n8.recursion_reverse_display\n9.reverse_list\n10.display_LL\n11.Exit\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertatbeg(head);
            break;
        case 2:
            head = insertatlast(head);
            break;
        case 3:
            head = insertatpos_after(head);
            break;
        case 4:
            head = insertatpos_before(head);
            break;
        case 5:
            head = begindelete(head);
            break;
        case 6:
            head = lastdelete(head);
            break;
        case 7:
            head = deletepos(head);
            break;
        case 8:
            recursion_reverse_display(head);
            printf("\n");
            break;
        case 9:
            head = reverse_list(head);
            break;
        case 10:
            display_LL(head);
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (1);
    return 0;
}
