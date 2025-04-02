#ifndef OPAQUE_H
#define OPAQUE_H
typedef struct Opaque Opaque;
Opaque* Opaque_init(int data);
int get_data(Opaque* ptr);
void set_data(Opaque* ptr, int data);
void deintit_Opaque(Opaque* ptr);

#endif