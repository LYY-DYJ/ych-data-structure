#include <stdio.h>
#include "List.h"
int main()
{
    List list;
    list.append(5);
    list.insert(0, 6);
    list.insert(1, 8);
    list.append(9);
    list.insert(0, 9);

    for (int i = 0; i < list.get_length(); i++)
    {
        printf("%d ", list.rcr_get_pos(i)->value);
    }
    printf("\n");

    list.rcr_remove_value(9);

    for (int i = 0; i < list.get_length(); i++)
    {
        printf("%d ", list.itr_get_pos(i)->value);
    }
    printf("\n");

    list.rcr_remove_value(9);
    list.append(7);

    for (int i = 0; i < list.get_length(); i++)
    {
        printf("%d ", list.itr_get_pos(i)->value);
    }
    printf("\n");

    list.rcr_reverse();

    for (int i = 0; i < list.get_length(); i++)
    {
        printf("%d ", list.itr_get_pos(i)->value);
    }
    printf("\n");

    for (int i = 0; i < list.get_length(); i++)
    {
        printf("%d ", list.get_pos_r(i)->value);
    }
    printf("\n");
}