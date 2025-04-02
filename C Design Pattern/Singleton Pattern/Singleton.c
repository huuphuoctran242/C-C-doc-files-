#include "Singleton.h"
#include <stdlib.h>
#include <stdio.h>

static Counter* Singleton_ptr = NULL;

Counter* getIstance(){
    if(Singleton_ptr ==NULL){
        Singleton_ptr = (Counter*)malloc(sizeof(Counter));
    
        if(Singleton_ptr !=NULL){
            Singleton_ptr->count = 0;
        }
    }
    return Singleton_ptr;
}
void update_cnt(){
    //Singleton_ptr->count++;
    Counter* ptr = getIstance();
    if(ptr !=NULL){
        ptr->count ++;
    }
}

int get_cnt(){
    Counter* ptr = getIstance();
    if(ptr !=NULL){
       return ptr->count;
    }
}
    