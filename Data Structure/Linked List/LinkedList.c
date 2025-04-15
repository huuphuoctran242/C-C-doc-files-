#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của 1 Node:
typedef struct Node {
    int data;
    struct Node* next;   
} Node;

// Hàm tạo Node mới: 
/*
- Tạo 1 con trỏ trỏ đến vùng nhớ của node mới.
- Gán data của node mới = data.
- Gán con trỏ next = NULL.
*/
Node* Node_Creation(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node-> next = NULL;
    return new_node;
}
// Ta dùng con trỏ HEAD để truy cập, duyệt list nên luôn phải truyền 
// con trỏ cấp 2 của head. 

// Thêm 1 Node vào đầu danh sách:
/*
- Tạo 1 node mới
- Set con trỏ next của node này = con trỏ HEAD hiện tại
- Chuyển HEAD sang node mới
*/
// Muốn thay đổi giá trị con trỏ thì phải truyền con trỏ cấp 2. 
void Insert_at_head(int data,Node **head){ 
    Node* new_node = Node_Creation(data);
    new_node->next = *head;
    *head = new_node; 
}

// Thêm 1 Node vào cuối danh sách: 
/*
- Tạo 1 Node mới
- Check xem List có đang trống không? Nếu trống thì gán head cho node mới
- Duyệt đến phần tử cuối
- Chuyển con trỏ next của node này sang node mới.
*/

void Insert_at_last(int data,Node** head){
    Node* new_node = Node_Creation(data);
    if(*head = NULL ){
        *head = new_node;
        return;
    }
    // Duyệt các phần tử trong list bằng 1 con trỏ tạm thời
    Node* tmp = *head; // Đầu list
    while(tmp->next != NULL){// Cứ duyệt đến khi tìm được node có next = NULL
        tmp = tmp->next; 
    }
    tmp->next = new_node;
}

// Thêm phần tử vào vị trí bất kì
/*
- Tạo node mới
- Truyền vị trí muốn thêm node: pos
- if pos < 1: return luôn
- if pos =1: Thêm vào đầu danh sách
- else: Duyệt đến phần tử thứ pos -1, chuyển next của nó sang node mới, 
chuyển next của node mới sang node thứ  pos
*/

void Insert_node(int data, int pos, Node** head){
    Node* new_node = Node_Creation(data);
    if (pos < 1){
        return;
    }
    if(pos == 1){
        new_node->next = *head;
        *head = new_node;
        return;
    }
    Node* tmp = *head; // tmp có cùng địa chỉ với HEAD của list,
    // nên mọi thay đổi của tmp cũng ảnh hưởng tới list thực tế.
    for(int i = 1; (i< pos -1)&& (tmp!= NULL); i++ ){
        tmp = tmp->next;
    }
    if(tmp == NULL){
        free(new_node);
        return;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
}

// Xóa một Node
/*
- check list trống
- if pos <1;
- if pos = 1;
- Duyệt đến phần tử thứ pos -1: Chuyển pos-1 ->next sang pos-1 ->next->next. 
- free node
*/

void delete_node(int pos, Node** head){
    if(*head == NULL || pos <1 ) return;
    Node* temp = *head;
    if(pos== 1){
        *head= temp->next;
    }
    for(int i = 1;i< pos -1 || temp->next != NULL; i++){
        temp = temp->next;
    }
    Node* nodetodelete = temp->next;
    temp->next = temp->next->next;
    free(nodetodelete);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head =NULL;
    Insert_at_head(10,&head);
    Insert_node(20,2,&head);
    printList(head);
}