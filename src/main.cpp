#include <iostream>
#include "Header.hpp"
#include <list>
#include <deque>
#include <random>
#include <algorithm>

int main(){
    //Важное условие, банки так то не хранят все кридиты в одном пуле, 
    //отдельно в наших деревянных, отдельно валютные так что контейнеров с разными валютами быть не может!
    std::deque<Credit> my_deq;
    for (int i = 0; i < 10; ++i){
        my_deq.push_back(generate_random_credit(std::to_string(i), "RUB"));
    }
    for (int i = 0; i < 10 ;++i){
        std::cout << my_deq[i];
        std::cout << std::endl;
    }

    std::sort(my_deq.begin(), my_deq.end()); 
    std::cout << "sorted" << std::endl;

    for (int i = 0; i < 10 ;++i){
        std::cout << my_deq[i];
        std::cout << std::endl;
    }

    std::cout << "copy" << std::endl;

    std::list<Credit> lst;
    std::copy(my_deq.begin(), my_deq.end(), std::back_inserter(lst));

    for (std::list<Credit>::iterator itr = lst.begin(); itr != lst.end(); ++itr){
        std::cout << *itr;
        std::cout << std::endl;
    }

}