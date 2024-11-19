#include<stdio.h>
#include<stdlib.h>
#include"common_head.hpp"
#include"Random_netlist_printer.hpp"

Random_netlist_printer& Random_netlist_printer::setwidth(int width)
{
    plain_width=width;
    return *this;
}

Random_netlist_printer& Random_netlist_printer::setheight(int height)
{
    plain_height=height;
    return *this;
}

Random_netlist_printer& Random_netlist_printer::set_rect_max_width(int width)
{
    rect_max_width=width;
    return *this;
}

Random_netlist_printer& Random_netlist_printer::set_rect_max_height(int height)
{
    rect_max_height=height;
    return *this;
}

void Random_netlist_printer::print(const char* output_filename,int rect_num)
{
    FILE *output_file=fopen(output_filename,"w");
    if(output_file==nullptr)
    {
        printf("Random netlist printer can't open file");
        return;
    }
    Rect rect;
    for(int i=0;i<rect_num;i++)
    {
        rect.x=rand()%(plain_width-1);
        rect.width=rand()%(rect_max_width)%(plain_width-rect.x-1)+1;
        rect.y=rand()%(plain_height-1);
        rect.height=rand()%(rect_max_height)%(plain_height-rect.y-1)+1;
        fprintf(output_file,"%d %d %d %d\n",rect.x,rect.y,rect.width,rect.height);
    }
    fclose(output_file);
    return;
}