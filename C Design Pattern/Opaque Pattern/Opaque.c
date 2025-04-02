#include <stdio.h>
#include <stdlib.h>
#include "Opaque.h"

struct Opaque{
    int data;
};
/*Ta có thể thấy ta đang tạo 1 local ptr rồi return nó ra ngoài
Trường hợp này vẫn valid vì con trỏ này được cấp phát động nên 
khi kế thúc hàm vùng nhớ này vẫn không bị clear như ở stack, nên 
việc return địa chỉ vùng nhớ trên heap ko vấn đề gì*/
Opaque* Opaque_init(int data){
    Opaque* ptr = (Opaque*)malloc(sizeof(Opaque));
    ptr->data = data;
    return ptr;
}
int get_data(Opaque* ptr){
    return ptr->data;
}
void set_data(Opaque* ptr,int data){
    ptr->data = data;
}
void deintit_Opaque(Opaque* ptr){
    free(ptr);
}
