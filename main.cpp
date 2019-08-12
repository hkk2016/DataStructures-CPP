#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};
static Node *GetNode(int data)
{
    Node *node = new Node();
    node->data = data;
    return node;
}
static Node *Insert(int data, Node *head)
{
    Node *newNode = GetNode(data);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head = newNode;
    return newNode;
}

static Node *InsertAt(int data, int position, Node *head)
{
    Node *heads = head;

    if (position == 1)
    {
        return Insert(data, head);
        ;
    }

    for (int i = 0; i < position - 2; i++)
    {
        head = head->next;
    }

    Node *temp = head->next;
    Node *newNode = GetNode(data);
    head->next = newNode;
    newNode->next = temp;

    return heads;
}

static Node *Delete(int position, Node *head)
{
    if (head == NULL)
        return head;

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        free(temp);

        return head;
    }

    Node *mainHead = head;

    for (int i = 0; i < position - 2; i++)
    {
        head = head->next;
    }

    Node *nodeToDelete = head->next;

    head->next = nodeToDelete->next;
    free(nodeToDelete);

    return mainHead;
}

static void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "\t";
        head = head->next;
    }

    cout << endl;
}

static Node *Reverse(Node *head)
{
    if (head == NULL)
        return head;
    Node *previous = NULL;
    Node *next = NULL;
    Node *current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;

    return head;
}

int main()
{
    Node *head = NULL;
    head = Insert(1, head);
    head = Insert(2, head);
    head = Insert(3, head);
    head = Insert(4, head);

    Print(head);

    head = InsertAt(10, 4, head);

    Print(head);

    head = Delete(5, head);

    Print(head);

    head = Reverse(head);

    Print(head);

    getchar();
}
