class Random_netlist_printer
{
private:
    int plain_width;
    int plain_height;
    int rect_max_width;
    int rect_max_height;
public:
    Random_netlist_printer():plain_width(100),plain_height(100),rect_max_width(1),rect_max_height(1){};
    ~Random_netlist_printer(){};
    Random_netlist_printer& setwidth(int width);
    Random_netlist_printer& setheight(int height);
    Random_netlist_printer& set_rect_max_width(int width);
    Random_netlist_printer& set_rect_max_height(int height);
    void print(const char*,int rect_num);
};

