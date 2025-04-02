#ifndef COUNTER_H
#define COUNTER_H
/*typedef được sử dụng để tạo một alias (biệt danh) cho kiểu dữ liệu
 struct Singleton.
Sau khi sử dụng typedef, kiểu dữ liệu struct Singleton
sẽ được gọi là Counter.
*/
typedef struct Singleton
{
    int count;
}Counter;

Counter* getIstance();
void update_cnt();
int get_cnt();

#endif