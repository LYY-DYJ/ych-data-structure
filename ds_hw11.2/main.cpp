#include"common_head.hpp"
#include"Wire_map.hpp"
#include"Random_netlist_printer.hpp"

int main()
{
    Wire_map wire_map;
    Random_netlist_printer random_netlist_printer;
    random_netlist_printer.setwidth(10000).setheight(10000).set_rect_max_width(100).set_rect_max_height(100).print("netlist",10000);
    wire_map.read_netlist("netlist");
    wire_map.write_netlist("output_netlist");
    return 0;
}