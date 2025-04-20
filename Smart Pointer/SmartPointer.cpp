#include <iostream>
#include <memory> 
//#define CASE_1
#ifdef CASE_1
void f(){
    int* ptr = new int(100);
}
int main(){
    while (1)
    {
        f();
    }
    return 0; 
}
#endif
//#define CASE_2
#ifdef CASE_2
class Car {
    public:
        Car(const std::string& brand) : brand(brand) {
            std::cout << "Car " << brand << " created!" << std::endl;
        }
        ~Car() {
            std::cout << "Car " << brand << " destroyed!" << std::endl;
        }
        void drive() {
            std::cout << "Driving " << brand << "!" << std::endl;
        }
    
    private:
        std::string brand;
    };
int main(){
    std::unique_ptr<Car> ptr1 = std::make_unique <Car> ("Honda");
    ptr1->drive();
    std::unique_ptr<Car> ptr2 = std::move(ptr1);
    if(ptr1 ==nullptr){
        ptr2->drive();
    }  
    return 0; 
}
#endif
//#define CASE_3
#ifdef CASE_3
class Car {
    public:
        Car(const std::string& brand) : brand(brand) {
            std::cout << "Car " << brand << " created!" << std::endl;
        }
        ~Car() {
            std::cout << "Car " << brand << " destroyed!" << std::endl;
        }
        void drive() {
            std::cout << "Driving " << brand << "!" << std::endl;
        }
    
    private:
        std::string brand;
    };

void func(std::shared_ptr<Car>* ptr){
    std::shared_ptr<Car> ptr3 = *ptr;
    std::cout<< ptr3.use_count()<<std::endl;
}
int main(){
    std::shared_ptr<Car> ptr1 = std::make_shared<Car> ("Toyota");
    ptr1->drive();
    std::shared_ptr<Car> ptr2 = ptr1;
    ptr2->drive();
    ptr1->drive();
    std::cout<< ptr1.use_count()<<std::endl;
    std::cout<< ptr2.use_count()<<std::endl;
    func(&ptr1);
    std::cout<< ptr1.use_count()<<std::endl;
    return 0; 
}
#endif

#define CASE_4 
#ifdef CASE_4

class B;  // Forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;  // shared_ptr trỏ đến đối tượng của B
    A() { std::cout << "A created!" << std::endl; }
    ~A() { std::cout << "A destroyed!" << std::endl; }
};

class B {
public:
    std::shared_ptr<A> a_ptr;  // shared_ptr trỏ đến đối tượng của A
    B() { std::cout << "B created!" << std::endl; }
    ~B() { std::cout << "B destroyed!" << std::endl; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_ptr = b;  // A trỏ đến B
    b->a_ptr = a;  // B trỏ đến A

    // Khi a và b ra khỏi phạm vi, bộ đếm tham chiếu của cả A và B vẫn là 1,
    // nên bộ nhớ sẽ không bị giải phóng và gây ra rò rỉ bộ nhớ.
}

#endif