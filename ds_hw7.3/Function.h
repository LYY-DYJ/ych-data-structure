class Function
{
    private:
        virtual double func(double x) const =0;
    public:
        virtual double operator()(double x) const=0;        
};

class Polynomial:public Function
{
    private:
        double func(double x) const;
        double* arg_list;
        int degree;

    public:
        Polynomial();
        Polynomial(int degree, double* arg_list);
        Polynomial(Polynomial& p);
        void operator=(Polynomial p);
        ~Polynomial();
        void set_arg(int n, double arg);
        void set_arg_list(double* arg_list);
        double operator()(double x)const;
        Polynomial integrate() const;
        Polynomial derivate() const;
};

