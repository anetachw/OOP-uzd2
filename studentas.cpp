#include "studentas.h"
#include "basic_funkcijos.h"


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

std::istream& Studentas::readStudent(std::istream& is) {
    is >> vardas_ >> pavarde_;
    paz_.clear();
    paz_.reserve(11);

    int pazymys;
    while(is >> pazymys){
        paz_.push_back(pazymys);
    }

    if (!paz_.empty()){
            egzaminas_ = paz_.back();
            paz_.pop_back();
    }
    return is;
}