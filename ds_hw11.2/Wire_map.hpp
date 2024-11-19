#include <vector>
#include <common_head.hpp>

class Wire_map
{
private:
    class Node
    {
    public:
        friend class Wire_map;
        Rect value;
        int parent;
        Node(Rect &val) : value(val), parent(-1) {};
        ~Node() {};
    };
    std::vector<Node> node_list;
    int find(int i);
    bool different(int i, int j);
    void attach(int i, int j);
    void add(Rect &val);
    bool overlap(Rect rect1, Rect rect2);

public:
    Wire_map() : node_list() {};
    ~Wire_map() {};
    void read_netlist(const char *);
    void write_netlist(const char *);
};

