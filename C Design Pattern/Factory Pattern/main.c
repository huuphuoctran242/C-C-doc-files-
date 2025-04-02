#include <stdio.h>
#include "Factory.h"
#include <stdlib.h>


int main() {
    // Tạo xe bằng Factory Pattern
    Car* sedan = create_car(SEDAN);
    Car* suv = create_car(SUV);
    Car* truck = create_car(TRUCK);

    // Lái xe
    sedan->drive(sedan);
    suv->drive(suv);
    truck->drive(truck);

    // Giải phóng bộ nhớ
    free(sedan);
    free(suv);
    free(truck);

    return 0;
}
