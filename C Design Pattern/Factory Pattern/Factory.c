#include "Factory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void drive_car(Car* car){
    printf("Driving a %s with %d wheels.\n", car->name, car->wheels);
}

Car* create_sedan() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car != NULL) {
        strcpy(car->name, "Sedan");
        car->wheels = 4;
        car->drive = drive_car;  // Gán phương thức lái xe
    }
    return car;
}

// Hàm tạo xe SUV
Car* create_suv() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car != NULL) {
        strcpy(car->name, "SUV");
        car->wheels = 4;
        car->drive = drive_car;  // Gán phương thức lái xe
    }
    return car;
}

// Hàm tạo xe Truck
Car* create_truck() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car != NULL) {
        strcpy(car->name, "Truck");
        car->wheels = 6;
        car->drive = drive_car;  // Gán phương thức lái xe
    }
    return car;
}

// Hàm tạo xe (Factory Method)
Car* create_car(CarType type) {
    switch (type) {
        case SEDAN:
            return create_sedan();
        case SUV:
            return create_suv();
        case TRUCK:
            return create_truck();
        default:
            return NULL;
    }
}