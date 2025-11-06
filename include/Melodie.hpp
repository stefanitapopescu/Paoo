#pragma once
#include <iostream>
#include <string>

class Melodie 
{
public:
    Melodie(std::string titlu, int minute);
    Melodie(const Melodie& other);
    Melodie(Melodie&& other) noexcept;
    ~Melodie();
    void setTitlu(std::string titlu);
    std::string getTitlu() const;
    void setMinute(int minute);
    int getMinute() const;
private:
    std::string titlu;
    int* minute;
};