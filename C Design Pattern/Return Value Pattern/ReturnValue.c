#include <stdio.h>

#define SUCCESS 0
#define DIVIDE_BY_0 1

int divide(int a,int b,float *result){
    if(b==0){
        return DIVIDE_BY_0;
    }
    *result = (float)a/b;
    return SUCCESS; 
}
int main(){
    float result = 0;
    int a =4;
    int b =3;
    int status = divide(a,b,&result);
    if(DIVIDE_BY_0 == status){
        printf("Error: Cannot divide by zero!\n");
    } else {
        printf("Result: %.2f\n", result); 
    }
}