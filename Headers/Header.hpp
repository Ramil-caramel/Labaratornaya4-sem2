#pragma once
#include <random>
class Credit
{
private:
    std::string name;
    unsigned int value;
    std::string valute;
    float prosent;
public:
    Credit(const Credit&) = default;
    Credit(Credit&&) = default;

    Credit& operator=(Credit&) = default;
    Credit& operator=(Credit&&) = default;

    Credit(std::string name = "", unsigned int value = 0, std::string valute = "RUB", float prosent = 0) : name{name}, value{value}, valute{valute}, prosent{prosent} {}
    
    friend std::ostream& operator<<(std::ostream&, const Credit&);

    bool operator==(const Credit& another_credit) const{
        return value == another_credit.value;
    }
    bool operator!=(const Credit& another_credit) const {
        return value != another_credit.value;
    }
    bool operator<(const Credit& another_credit) const {
        return value < another_credit.value;
    }
    bool operator<=(const Credit& another_credit) const {
        return (*this < another_credit) || (*this == another_credit);
    }
    bool operator>(const Credit& another_credit) const {
        return another_credit < *this;
    }
    bool operator>=(const Credit& another_credit) const {
        return another_credit <= *this;
    }

};

std::ostream& operator<<(std::ostream& out, const Credit& credit){
    out << credit.name << " " << credit.value << " " << credit.valute << " " << credit.prosent;
    return out;
}


Credit generate_random_credit(std::string name,std::string valute) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<float> prosent_dist(1.0, 100.0);
    float prosent = prosent_dist(gen);

    std::uniform_int_distribution<unsigned int> value_dist(1000, 100000000);
    unsigned int value = value_dist(gen);

    return Credit(name, value, valute, prosent);
}