#include <math.h>
//����point����
class point{
    //����˽�б���x,y
    private:
        double x=0;
        double y=0;
    //�����������ӿ�
    public:
        //y���䣬����x��ֵ
        void set_x(double x);
        //x���䣬����y��ֵ
        void set_y(double y);
        //��ȡx
        double get_x();
        //��ȡy
        double get_y();
        //theta���䣬����x��ֵ
        void set_rou(double rou);
        //row���䣬����x��ֵ
        void set_theta(double theta);
        //��ȡrou
        double get_rou();
        //��ȡtheta
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