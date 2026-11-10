#include "studentas.h"
#include "basic_funkcijos.h"


Studentas::Studentas(std::istream& is) { 
  readStudent(is);  
}

double Studentas::galBalas(double (*funkcija) (std::vector<int>)) const {
    if (paz_.empty()){
        return 0.6 * egzaminas_;
    }
    double nd_galutinis = funkcija(paz_);
    return 0.4 * nd_galutinis + 0.6 * egzaminas_;

}

std::istream& Studentas::readStudent(std::istream& is) {
    if (&is == &std::cin){
        std::cout << "Įveskite per tarpa studento vardą ir pavardę: ";
    }

    if (!(is >> vardas_ >> pavarde_)) return is;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    

    if (&is == &std::cin) {
        std::cout << "Įveskite namų darbų pažymius (palikite tuščią irspauskite ENTER, kad baigti):\n";
    }

    paz_.reserve(11);
    std::string input1;
    int i = 1;
    while (true) {
        if (&is == &std::cin) {
            std::cout << "Įveskite #" << i << " pažymį: ";
        }
        
        std::getline(is, input1);
        if (input1.empty()) break;

        try {
            int a = std::stoi(input1);
            if (a >= 1 && a <= 10) {
                paz_.push_back(a);
                i++;
            } else if(&is == &std::cin) {
                std::cout << "Klaida! Pažymis turi būti nuo 1 iki 10.\n";
            }
        } catch (...) {
            if (&is == &std::cin) {
                std::cout << "Klaida! Įvedėte ne skaičių.\n";
            }
        }
    }

    while (true) {
        if (&is == &std::cin) {
            std::cout << "Įveskite egzamino pažymį: ";
        }
        
        std::getline(is, input1);
        try {
            egzaminas_ = std::stoi(input1);
            if (egzaminas_ >= 1 && egzaminas_ <= 10) {
                break;
            } else if (&is == &std::cin) {
                std::cout << "Klaida! Pažymis turi būti nuo 1 iki 10.\n";
            }
        } catch (...) {
            if (&is == &std::cin) {
                std::cout << "Klaida! Įvedėte ne skaičių.\n";
            }
        }
    }

    return is;
};