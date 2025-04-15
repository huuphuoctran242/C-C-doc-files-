#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  

typedef struct Stack {
    int arr[MAX];
    int top_index;
}Stack;

// Khởi tạo Stack
/*
- Tạo 1 stack bằng cách tạo 1 đối tượng Stack và cho top_index = -1 
*/
void init_Stack(Stack* stack){
    stack->top_index = -1;
}
// Thêm giá trị vào stack
/*
- Kiểm tra xem stack đầy chưa
- Tăng top_index và gán giá trị
*/
void push(Stack* stack, int data){
    if(stack->top_index >= MAX -1){
        return -1;
    }
    ++stack->top_index;
    stack->arr[stack->top_index] = data;
    //stack->arr[++stack->top_index]= data;
}

// Lấy ra giá trị trên top:
/*
- Check xem stack có rỗng không 
- Lấy ra giá trị trên top, xóa trong stack và cập nhập top_index

*/

int pop(Stack* stack){
    if(stack->top_index == -1){
        return -1;
    }
    return stack->arr[stack->top_index--];
}

// Hàm lấy phần tử trên cùng của Stack mà không loại bỏ
int top(Stack*stack){
    if(stack->top_index == -1){
        return -1;
    }
    return stack->arr[stack->top_index];
}

bool empty(Stack* stack){
    if(stack->top_index == -1){
        return true;
    }
    else return false;
}
// Hàm lấy kích thước (số phần tử) của Stack
int size(Stack* stack) {
    return stack->top_index + 1; 
}
int main(){
    Stack stack;
    init_Stack(&stack);
    
}