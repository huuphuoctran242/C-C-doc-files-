#include <stdio.h>
//#define Case_1 
#ifdef Case_1 

#include <stdio.h>

/*Định nghĩa kiểu callback - function pointer*/
typedef void(*Callback)(int data);

/*Định nghĩa hàm chính*/
void processing_data(int data, Callback callback_func){
    printf("Do some logic in prcessing_data \n");
    callback_func(data);
}
/*Định nghĩa hàm call back*/
void call_back(int data){
    printf("Do somethings in call_back with data: %d \n",data);
}


int main(){
    processing_data(4,call_back);
}
#endif
// Sử dụng callback giữa các layer
// Layer cao hơn có thể gọi trực tiếp fucntion của lớp thấp hơn. 
// Lớp thấp hơn gọi function lớp cao hơn qua callback 
// VÌ lớp thấp hơn không quan tâm lớp cao hơn cái mẹ gì trong bụng hết
#define Case_2 
#ifdef Case_2

/*High layer - Manager.c*/

void on_data_processed(int result){
    printf("Kết quả xử lý : %d",result);
}

/* Lower layer - Processor.c*/
typedef void(*Callback)(int result);
void process_data(int data,Callback callback_func){
    int result = data*2; // Giả sử xử lý dữ liệu
    callback_func(result);// gọi call back để thông báo kết quả
}

/*main.c*/
int main(){
    int value =4;
    process_data(value,on_data_processed);
}

#endif