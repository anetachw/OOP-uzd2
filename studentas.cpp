#include "studentas.h"
#include "basic_funkcijos.h"
#include "template_funkcijos.h"
#include <sstream>
#include <iomanip>


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

Studentas::Studentas(const Studentas& other)
    : Zmogus(other),
      paz_(other.paz_), 
      egzaminas_(other.egzaminas_), 
      galutinis_vid_(other.galutinis_vid_), 
      galutinis_med_(other.galutinis_med_) {};


Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        paz_ = other.paz_;
        egzaminas_ = other.egzaminas_;
        galutinis_vid_ = other.galutinis_vid_;
        galutinis_med_ = other.galutinis_med_;
    }
    return *this;
};


std::istream& Studentas::readStudent(std::istream& is) {
   if (!(is >> vardas_ >> pavarde_)) return is;
    
    paz_.clear();
    paz_.reserve(11);
    int pazymys;
    
    std::string eilute;
    std::getline(is, eilute);
    static std::stringstream ss;
    ss.clear();
    ss.str(eilute);

    while (ss >> pazymys) {
        paz_.push_back(pazymys);
    }
    
    if (!paz_.empty()) {
        egzaminas_ = paz_.back(); 
        paz_.pop_back();                       
    }
    galBalas();

    return is;
};

void Studentas::zmogus_info() const {
    std::cout << vardas_ << " " << pavarde_ << '\n';

}

std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
};

std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << "|" << std::left << std::setw(14) << s.vardas()
       << "|" << std::left << std::setw(16) << s.pavarde() << "|"
       << std::left << std::setw(16) << std::fixed << std::setprecision(2) << s.galutinis_vid() << "|"
       << std::left << std::setw(16) << std::fixed << std::setprecision(2) << s.galutinis_med() << "|";
    return os;
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