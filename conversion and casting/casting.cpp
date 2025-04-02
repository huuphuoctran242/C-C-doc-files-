#include <iostream>
#include <cstdint>
using namespace std;


//#define Case_1 // Type conversion example
#ifdef Case_1
int main(){
int i =10;
char c ='A';
cout<<(int)c<<endl;

char sum = i+c;
cout<<sum<<endl;
cout<<sizeof(sum)<<endl;
}
#endif

//#define Case_2 
#ifdef Case_2 

void display(char x){
    cout <<x<<endl;
}
int main(){
    int x =55; //0000 0000 0011 0111
    display(x); // 7 = 0111
}

#endif

//#define Case_3 
#ifdef Case_3 

int main(){
    float a = 3.14f;
    uint16_t b = a;
    cout <<b<<endl;
    cout<<sizeof(a);
}
#endif

#define Case_4 
#ifdef Case_4 
int main() {
  
    int i = 10;
    char c = 'a';

    // c implicitly converted to int. ASCII
    // value of 'a' is 97
    i = i + c;

    // x is implicitly converted to float
    float f = i + 1.0;

    cout << "i = " << i << endl
         << "c = " << c << endl
         << "f = " << f;

    return 0;
}

#endif