#include "Melodie.hpp"
#include <vector>

int main()
{
    
    std::cout << " Constructor Normal ---\n";
    Melodie melodie1("Believer", 3);
    std::cout << "Date: " << melodie1.getTitlu() << " - " << melodie1.getMinute() << " minute\n\n";

    std::cout << "--- Copy Constructor (Deep Copy) ---\n";

    Melodie melodie2 = melodie1;  
    
    melodie2.setTitlu("Thunder");
    melodie2.setMinute(4);
    
    std::cout << "\nVerificăm că sunt independente (DEEP COPY funcționează):\n";
    std::cout << "  Original: " << melodie1.getTitlu() << " - " << melodie1.getMinute() << " min\n";
    std::cout << "  Copia:    " << melodie2.getTitlu() << " - " << melodie2.getMinute() << " min\n";
    std::cout << "Valorile sunt diferite - obiectele sunt independente!\n\n";

    std::cout << "--- Move Constructor  ---\n";
    std::cout << "Exemplu 1: Transfer explicit cu std::move()\n";
    Melodie melodie3 = std::move(melodie1);
    
    std::cout << "\nDupă mutare:\n";
    std::cout << "melodie3: " << melodie3.getTitlu() << " - " << melodie3.getMinute() << " min\n";

    std::cout << "\nExemplu 2: Move implicit la inserare în vector \n";
    std::vector<Melodie> playlist;
    std::cout << "Adăugăm melodie2 în vector cu std::move():\n";
    playlist.push_back(std::move(melodie2));
    std::cout << "→ Vector preia ownership-ul, melodie2 este invalidată!\n";
    std::cout << "Vector conține: " << playlist[0].getTitlu() << " - " << playlist[0].getMinute() << " min\n\n";

    std::cout << "--- Încapsulare ---\n";
    Melodie melodie5("Natural", 8);
    melodie5.setMinute(10);  
    std::cout << "Melodie modificată: " << melodie5.getTitlu() << " - " << melodie5.getMinute() << " min\n\n";

    return 0;
}
