#include <iostream>
#include <iomanip>
#include "CircleBuffer.h"

int main() {
    std:: vector<int> a = {0, 1, 2};
    CircleBuffer<int> c(a);
    std:: cout << std:: setw(3) << std:: left;
    c.add(a);



    for(int i = -20; i <= 20; i++){
        std:: cout << std:: setw(3) << std:: left << i;
    }
    std:: cout << std:: endl;
    for(int i = -20; i <= 20; i++){
        std:: cout << std:: setw(3) << std:: left<<c[i];
    }

    return 0;


}
