#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> paz_;
    int egzaminas_;

public:
    Studentas() : egzaminas_(0) { };  
    Studentas(std::istream& is);
    inline std::string vardas() const { return vardas_; }    
    inline std::string pavarde() const { return pavarde_; } 
    inline const std::vector<int>& paz() const { return paz_; }
    inline int egz() const { return egzaminas_; } 

    std::istream& readStudent(std::istream&);
    double galBalas(double (*funkcija) (std::vector<int>)) const;
    void setVardas(const std::string& v) { vardas_ = v; }
    void setPavarde(const std::string& p) { pavarde_ = p; }
    void setPazymis(int paz) { paz_.push_back(paz); }
    void setEgzaminas(int egz) { egzaminas_ = egz; }   
};

bool compareVP(const Studentas& a, const Studentas& b);
bool compareEgzaminas(const Studentas& a, const Studentas& b);
bool compareGalBalas(const Studentas& a , const Studentas& b);

