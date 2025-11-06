#include "Melodie.hpp"

Melodie::Melodie(std::string titlu, int minute) : titlu(titlu)
{
    this->minute = new int(minute);
    std::cout << "[CONSTRUCTOR] Creat obiect: " << titlu << " (" << minute << " min)\n";
}

Melodie::Melodie(const Melodie& other)
{
    titlu = other.titlu;
    minute = new int(*(other.minute));
    std::cout << "[COPY CONSTRUCTOR] Copiat obiect: " << titlu << "\n";
}

Melodie::Melodie(Melodie&& other) noexcept
{
    titlu = std::move(other.titlu);
    minute = other.minute;        
    other.minute = nullptr;        
    std::cout << "[MOVE CONSTRUCTOR] Mutat obiect: " << titlu << "\n";
}

Melodie::~Melodie()
{
    if (minute != nullptr) {
        std::cout << "[DESTRUCTOR] Eliberat obiect: " << titlu << "\n";
        delete minute;
    } else {
        std::cout << "[DESTRUCTOR] Obiect deja mutat (nullptr)\n";
    }
}

void Melodie::setTitlu(std::string titlu)
{
    this->titlu = titlu;
}

std::string Melodie::getTitlu() const
{
    return titlu;
}

void Melodie::setMinute(int minute)
{
    if (this->minute != nullptr) {
        *(this->minute) = minute;
    } else {
        std::cout << "[EROARE] Obiect mutat, nu mai are date!\n";
    }
}

int Melodie::getMinute() const
{
    if (minute != nullptr) {
        return *minute;
    } else {
        std::cout << "[EROARE] Obiect mutat, nu mai are date!\n";
        return -1;
    }
}
