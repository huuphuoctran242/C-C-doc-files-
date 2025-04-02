#include <stdio.h>



//#define CASE_1
#ifdef CASE_1

typedef struct {
    int data_1;
    int data_2;
}Data;

void init_Data(Data* self){
    memset(self,0,sizeof(*self));
}
void deinit_Data(){

}
#endif
#define CASE_2
#ifdef CASE_2
// Định nghĩa trước kiểu Hinh_chu_nhat, để dùng trong struct, neu khong 
//khong the khai bao 2 function pointer trong struct được
typedef struct Hinh_chu_nhat Hinh_chu_nhat;
struct Hinh_chu_nhat {
    float length;
    float width;
    // Con trỏ hàm để tính diện tích và chu vi
    float (*dien_tich)(Hinh_chu_nhat*);
    float (*Chu_vi)(Hinh_chu_nhat*);
};

// Hàm tính diện tích
float dientich_func(Hinh_chu_nhat* ptr) {
    return (ptr->length * ptr->width);
}

// Hàm tính chu vi
float chuvi_func(Hinh_chu_nhat* ptr) {
    return 2 * (ptr->length + ptr->width);
}

// Constructor cho Hinh_chu_nhat
void init_Hinh_chu_nhat(Hinh_chu_nhat* ptr, float length, float width) {
    ptr->length = length;
    ptr->width = width;
    ptr->dien_tich = dientich_func;  // Gán hàm cho con trỏ hàm dien_tich
    ptr->Chu_vi = chuvi_func;        // Gán hàm cho con trỏ hàm Chu_vi
}

int main() {
    Hinh_chu_nhat hinhchunhat;
    init_Hinh_chu_nhat(&hinhchunhat, 10, 5);
    
    // In diện tích và chu vi với %f cho kiểu float
    printf("Dien tich hinh chu nhat la: %.2f\n", hinhchunhat.dien_tich(&hinhchunhat));
    printf("Chu vi hinh chu nhat la: %.2f\n", hinhchunhat.Chu_vi(&hinhchunhat));
    
    return 0;
}
#endif