#include<iostream>
#include<cassert>


class A{
    public:
        void set_a(int a){this->a_ = a;}
        int get_a(){return this->a_;}

    private:
        int a_;
};

class B:public A{
    public:
        void set_ab(int a, int b);
        int get_b();

    private:
        int b_;
};

void B::set_ab(int a, int b){
    this->b_ = b;
    this->set_a(a);
}

int B::get_b(){
    return this->b_;
}


class C:public B{
    public:
        void set_abc(int a, int b, int c);
        int get_c();
    private:
        int c_;
};

void C::set_abc(int a, int b, int c){
    this->set_ab(a, b);
    this->c_ = c;
}

int C::get_c(){
    return this->c_;
}

int main(){
    C c;
    c.set_abc(1,2,3);
    assert(c.get_a() == 1);
    assert(c.get_b() == 2);
    assert(c.get_c() == 3);
}