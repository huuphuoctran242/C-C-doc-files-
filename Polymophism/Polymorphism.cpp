#include <iostream>
using namespace std;

/********************************************/
//#define Case_1 //function overload
//#define Case_2 // overloading operator
//#define Case_3 // Virtual function
//#define Case_4 // Base class pointer as function parameter
#define Case_5 // Static dispatch
/********************************************/




#ifdef Case_1 //function overload
class Math{
public:
    int add(int a,int b){
        return a+b;
    }
    double add(double a,double b){
        return a+b;
    }
};
int main(){
    Math math;
    cout<<math.add(1,2)<<endl;
    cout<<math.add(2.1,1.2)<<endl;
    // Số thực tự động được hiểu là kiểu double
    // nên ở đây hàm mà định nghĩa là float( ...) 
    // là sẽ lỗi
}
#endif
#ifdef Case_2 //Operator overloading

class Vector{
private:
    int a,b;
public:
    Vector(int a =0,int b = 0):a(a),b(b){}
    Vector operator+(const Vector& other){
        return Vector(a+other.a,b+other.b);
    }
    void display(){
        cout<<a<<" ,"<<b<<endl;
    }
};
int main(){
    Vector a(1,2),b(3,4);
    Vector c = a+b;
    c.display();
}

#endif

#ifdef Case_3 // Virtual function

class Animal{
public:
    // Không có 'virtual' thì auto gọi method lớp cha
    virtual void makeSound(){
        cout<<"Animal make sound"<<endl;
    }
};
class Dog:public Animal{
public:
    void makeSound(){
        cout<<"Gâu gâu"<<endl;
    }
};
class Cat : public Animal {
public:
    void makeSound(){
        cout<<"Mèo méo meo mèo meo"<<endl;
    }
};
int main(){
    Animal* animal_1;
    Animal* animal_2 = new Cat();
    Dog dog;
    animal_1 =&dog;

    animal_1->makeSound();
    animal_2->makeSound();
    delete animal_2;
    //animal 1 trỏ vùng nhớ trên stack
    // animal 2 trỏ đến vùng nhớ heap 
}
#endif
#ifdef Case_4 // Base class pointer as function parameter

class Shape{
public:
    virtual void draw(){
        cout<<"draw a shape"<<endl;
    }
};
class Circle : public Shape{
public:
    void draw() override;
    //Chỉ cần 'override ở đây, không cần dùng trong define hàm nữa       
};
void Circle::draw(){
    cout<<"draw a Circle"<<endl;
}
class Square :public Shape{
public:
    void draw() override;
};
void Square::draw(){
    cout<<"draw a Square"<<endl;
}
// Truyền vào 1 con trỏ Base
void show_the_draw(Shape* shape){
    shape->draw();
}
int main(){
Circle circle;
Square square;
show_the_draw(&circle);
show_the_draw(&square);
// Hàm có thể nhận bất kì đối tượng nào kế thừa từ Shape
}
#endif
#ifdef Case_5

class Foo{
public:
    void method_1(){
        cout <<"Foo Method 1"<<endl;
    }
    void method_2();
};
void Foo::method_2(){
    cout<<"Foo Method 2"<<endl;
}
int main(){
    return 0;
}
#endif
