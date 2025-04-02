#ifndef CAR_H
#define CAR_H

typedef enum{
    SEDAN,
    SUV,
    TRUCK
}CarType;

typedef struct Car
{
    char name[50];
    int wheels;
    void (*drive)(struct Car*);
}Car;

Car* create_car(CarType type);
#endif