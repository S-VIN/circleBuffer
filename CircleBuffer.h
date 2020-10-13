//
// Created by stepan on 13.10.2020.
//
#ifndef CIRCLEBUFFER_CIRCLEBUFFER_H
#define CIRCLEBUFFER_CIRCLEBUFFER_H
#include <vector>

template<typename T>
class CircleBuffer{
private:
    std:: vector<T> buffer;
    int iterator = 0;

public:
    CircleBuffer(std:: vector<T> input){
        buffer = input;
    }

    CircleBuffer(T input){
        buffer.push_back(input);
    }

    void add(std:: vector<T> input){
        buffer.insert(std::end(buffer), std::begin(input), std::end(input));
    }

    void add(T input){
        buffer.push_back(input);
    }

    void pop(){
        buffer.pop_back();
    }

    unsigned long getLength()const {
        return buffer.size();
    }

    void iterate(){
        iterator++;
        if(iterator >= buffer.size()) {
            iterator = 0;
        }
    }

    T get()const{
        return buffer[iterator];
    }

    T operator[](int i){
        unsigned long index;
        if(i < 0){
            //i don`t know how it works, fuck %
            index = buffer.size() - ((-1 * i - 1) % buffer.size()) - 1;
        }else {
            index = i % buffer.size();
        }
        return buffer[index];
    }
};


#endif //CIRCLEBUFFER_CIRCLEBUFFER_H
