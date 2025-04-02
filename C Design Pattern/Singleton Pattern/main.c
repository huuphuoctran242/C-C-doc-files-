#include <stdio.h>
#include "Singleton.h"

int main(){
    update_cnt();
    update_cnt();
    update_cnt();
    update_cnt();
    printf("Counter: %d \n",get_cnt());
    return 0;
}