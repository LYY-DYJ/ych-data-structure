#include<stdio.h>

struct Node
{
    int value;
    Node *next;
};

Node *make_node(int n)
{
    Node *ptr;
    ptr = new Node;
    ptr->value = n;
    ptr->next = nullptr;
    return ptr;
}

Node *joseph(int n, int s, int m);

int main()
{
    Node* head;
    Node* curr;
    head=joseph(8,1,2);
    for(curr=head;curr!=nullptr;curr=curr->next)
    {
        printf("%d ",curr->value);
    }
    printf("\n");
}

Node *joseph(int n, int s, int m)
{
    Node *head=nullptr;
    Node *tail=nullptr;
    Node *prev=nullptr;
    Node *head_ring=nullptr;
    Node *tail_ring=nullptr;
    head_ring = make_node(1);
    tail_ring = head_ring;
    for (int i = 2; i <= n; i++)
    {
        tail_ring->next = make_node(i);
        tail_ring = tail_ring->next;
    }
    tail_ring->next = head_ring;

    prev = tail_ring;
    for (int i = 1; i <= s - 1; i++)
    {
        prev = prev->next;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m-1; j++)
        {
            prev = prev->next;
        }
        if(i==1)
        {
            head=prev->next;
            tail=head;
        }
        else
        {
            tail->next=prev->next;
            tail=tail->next;
        }
        prev->next=prev->next->next;
    }
    tail->next=nullptr;

    return head;
}