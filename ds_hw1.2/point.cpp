#include <math.h>
//定义point对象
class point{
    //定义私有变量x,y
    private:
        double x=0;
        double y=0;
    //声明对象函数接口
    public:
        //y不变，设置x的值
        void set_x(double x);
        //x不变，设置y的值
        void set_y(double y);
        //读取x
        double get_x();
        //读取y
        double get_y();
        //theta不变，设置x的值
        void set_rou(double rou);
        //row不变，设置x的值
        void set_theta(double theta);
        //读取rou
        double get_rou();
        //读取theta
        double get_theta();
};

void point::set_x(double x){
    this->x = x;
}

void point::set_y(double y){
    this->y = y;
}

double point::get_x(){
    return this->x;
}

double point::get_y(){
    return this->y;
}

double point::get_rou(){
    return sqrt(this->x*this->x+this->y*this->y);
}

double point::get_theta(){
    return atan2(this->y,this->x);
}

void point::set_rou(double rou){
    double rou_prev=this->get_rou();
    this->x=(rou/rou_prev)*this->x;
    this->y=(rou/rou_prev)*this->y;
}

void point::set_theta(double theta){
    double rou_prev=this->get_rou();
    this->x=rou_prev*cos(theta);
    this->y=rou_prev*sin(theta);
}