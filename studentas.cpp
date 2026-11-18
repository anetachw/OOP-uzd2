#include "studentas.h"
#include "basic_funkcijos.h"
#include "template_funkcijos.h"
#include <sstream>


Studentas::Studentas(std::istream& is) { 
  readStudent(is);  
}

void Studentas::galBalas() {
    if (paz_.empty()){
        galutinis_vid_ = 0.6 * egzaminas_;
        galutinis_med_ = 0.6 * egzaminas_;
    } else {
        galutinis_vid_ = 0.4 * vidurkis(paz_) + 0.6 * egzaminas_;
        galutinis_med_ = 0.4 * mediana(paz_) + 0.6 * egzaminas_;
    }
};

Studentas::~Studentas() {
    vardas_.clear();
    pavarde_.clear();
    paz_.clear();
    egzaminas_ = 0;
};

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
    galBalas();

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
    return a.galutinis_vid() > b.galutinis_vid();
};