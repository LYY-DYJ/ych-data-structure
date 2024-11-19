#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <common_head.hpp>
#include <Wire_map.hpp>

int Wire_map::find(int i)
{
    if (node_list[i].parent == -1)
        return i;
    int root = find(node_list[i].parent);
    node_list[i].parent = root;
    node_list[root].childs.push_back(i);
    node_list[root].tree_size += 1;
    return root;
}

bool Wire_map::different(int i, int j)
{
    return find(i) != find(j);
}

void Wire_map::attach(int i, int j)
{
    node_list[i].parent = j;
    node_list[j].childs.push_back(i);
    node_list[j].tree_size += node_list[i].tree_size;
}

void Wire_map::unian(int i, int j)
{
    if (different(i, j))
    {
        if (node_list[i].tree_size < node_list[j].tree_size)
        {
            attach(i, j);
        }
        else
        {
            attach(j, i);
        }
    }
}

bool Wire_map::overlap(Rect rect1, Rect rect2)
{
    return ((rect1.x <= rect2.x + rect2.width) && (rect2.x <= rect1.x + rect1.width)) && (rect1.y <= rect2.y + rect2.height) && (rect2.y <= rect1.y + rect1.height);
}

void Wire_map::add(Rect &val)
{
    Node new_node = Node(val);
    node_list.push_back(new_node);
    int new_node_index = int(node_list.size()) - 1;
    for (int i = 0; i < new_node_index; i++)
    {
        if (overlap(node_list[i].value, val) && different(i, new_node_index))
            attach(find(i), new_node_index);
    }
}

void Wire_map::read_netlist(const char *input_filename)
{
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == nullptr)
    {
        printf("Can't open file!\n");
        return;
    }
    char line[256];
    char *token;
    int num;
    Rect rect;
    while (fgets(line, sizeof(line), input_file))
    {

        token = strtok(line, " ");
        num = atoi(token);
        rect.x = num;
        token = strtok(nullptr, " ");
        num = atoi(token);
        rect.y = num;
        token = strtok(nullptr, " ");
        num = atoi(token);
        rect.width = num;
        token = strtok(nullptr, " ");
        num = atoi(token);
        rect.height = num;
        add(rect);
    }
    fclose(input_file);
}

void Wire_map::write_netlist(const char *output_filename)
{
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == nullptr)
    {
        printf("Can't write file!\n");
        return;
    }
    for (int i = 0, net_num = 0; i < int(node_list.size()); i++)
    {
        if (node_list[i].parent == -1)
        {
            fprintf(output_file, "net%d:\n", net_num);
            for (int j = 0; j < int(node_list.size()); j++)
            {
                if (find(j) == i)
                {
                    Node node(node_list[j]);
                    Rect rect = node.value;
                    fprintf(output_file, "%d:(%d,%d,%d,%d)\n",j, rect.x, rect.y, rect.width, rect.height);
                }
            }
            net_num++;
        }
    }
    fclose(output_file);
    return;
}
