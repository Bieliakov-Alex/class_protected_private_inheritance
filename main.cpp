#include <iostream>

class A{
public:
    A():
    x{0}{}
    A(int arg):
    x{arg}{}
    void public_print(){
        std::cout<<"Public print X: "<<x<<std::endl;
    }
protected:
    void print(){
        std::cout<<"X: "<<x<<std::endl;
    }
private:
    int x;
};

class B1: public A{
public:
    void b1_print(){
        print();
    }
};

class B11: public B1{
public:
    void b11_print(){
        print();
    }
};

class B2: protected A{
public:
    void b2_print(){
        public_print();
    }
};

class B22: protected B2{
public:
    void b22_print(){
        print();
    }
};

class C1: private A{
public:
    void c1_print(){
        public_print();
        print();
    }
};

class C11: public C1{
public:
    void c11_print(){
        //public_print();
        //print();
    }
};

class C2: A{
public:
    void c2_print(){
        public_print();
        print();
    }
};

class C22: public C2{
public:
    void c22_print(){
        //public_print();
        //print();
    }
};

int main(){
    A a{5};
    //a.print();
    a.public_print();
    B1 b1;
    //b1.print();
    b1.b1_print();  

    B11 b11;
    //b11.print();
    b11.b11_print();

    B2 b2;
    //b2.public_print();
    b2.b2_print();

    B22 b22;
    b22.b22_print();

    C1 c1;
    //c1.print();
    //c1.public_print();
    c1.c1_print();

    C11 c11;
    //c11.print();
    //c11.public_print();
    c11.c11_print();

    C2 c2;
    //c2.print();
    //c2.public_print();
    c2.c2_print();

    C22 c22;
    //c22.print();
    //c22.public_print();
    c22.c22_print();
    return 0;
}