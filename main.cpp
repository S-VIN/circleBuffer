#include <iostream>
#include <iomanip>
#include <vector>
#include "stdlib.h"

using namespace std;


template<typename T>
class CircleBuffer{
private:
    vector<T> buffer;
    int iterator = 0;
public:
    void add(vector<T> input){
        buffer.insert(std::end(buffer), std::begin(input), std::end(input));
    }

    void add(T input){
        buffer.push_back(input);
    }

    void pop(){
        buffer.pop_back();
    }

    int getLength()const {
        return buffer.size();
    }

    void iterate(){
        iterator++;
        if(iterator >= buffer.size()) {
            iterator = 0;
        }
    }

    T getMember()const{
        return buffer[iterator];
    }

    T operator[](int i){
        if(i < 0){
            //i--;
        }
        int index = i % buffer.size();
        return buffer[index];
    }
};

/*ostream& operator>>(ostream& os, CircleBuffer& circleBuffer){
    for(int i = 0; i < circleBuffer.getLength(); i++){
        os << circleBuffer.getMember() << " ";
        circleBuffer.iterate();
    }
}*/


int main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CircleBuffer<int> c;
    cout << setw(3) << left;
    c.add(a);
    //cout >> c;
    for(int i = -20; i <= 20; i++){
        cout << setw(3) << left << i;
    }
    cout << endl;
    for(int i = -20; i <= 20; i++){
        cout << setw(3) << left<<c[i];
    }

    return 0;
}
