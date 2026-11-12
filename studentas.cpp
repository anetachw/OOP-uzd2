#include "studentas.h"
#include "basic_funkcijos.h"
#include "template_funkcijos.h"
#include <sstream>


Studentas::Studentas(std::istream& is) { 
  readStudent(is);  
}

double Studentas::galBalas(double (*funkcija) (std::vector<int>) = vidurkis) const {
    if (paz_.empty()){
        return 0.6 * egzaminas_;
    }
    double nd_galutinis = funkcija(paz_);
    return 0.4 * nd_galutinis + 0.6 * egzaminas_;

}

Studentas::~Studentas() {
    paz_.clear();
}

std::istream& Studentas::readStudent(std::istream& is) {
   if (!(is >> vardas_ >> pavarde_)) return is;
    
    paz_.clear();
    paz_.reserve(10);
    int pazymys;
    
    std::string eilute;
    std::getline(is, eilute);
    std::stringstream ss(eilute);
    
    std::vector<int> temp_paz;
    temp_paz.reserve(11);

    while (ss >> pazymys) {
        temp_paz.push_back(pazymys);
    }
    
    if (!temp_paz.empty()) {
        egzaminas_ = temp_paz.back(); 
        temp_paz.pop_back();          
        paz_ = temp_paz;              
    }

    return is;
};

bool compareVP(const Studentas& a, const Studentas& b){
    if (a.pavarde() != b.pavarde()){
            return a.pavarde() < b.pavarde();
        }
    return a.vardas() < b.vardas();
};

bool compareEgzaminas(const Studentas& a, const Studentas& b){
    return a.egz() > b.egz();
};

bool compareGalBalas(const Studentas& a , const Studentas& b){
    return a.galBalas() > b.galBalas();
};