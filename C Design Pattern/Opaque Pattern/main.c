#include "Opaque.h"
#include<stdio.h>
int main(){
    Opaque* obj = Opaque_init(24);
    printf("Gia tri cua data: %d\n",get_data(obj));
    set_data(obj,14);
    printf("Gia tri cua data: %d\n",get_data(obj));
    deintit_Opaque(obj);
    return 0;
}