#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <utility>


class Zmogus{
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus() = default;
    Zmogus(std::string vardas, std::string pavarde)
        : vardas_(std::move(vardas)), pavarde_(std::move(pavarde)) {}

    virtual ~Zmogus();

    inline std::string vardas() const { return vardas_; }    
    inline std::string pavarde() const { return pavarde_; } 

    void setVardas(const std::string& v) { vardas_ = v; }
    void setPavarde(const std::string& p) { pavarde_ = p; }

    virtual void zmogus_info() const = 0;
};


class Studentas: public Zmogus {
private:
    std::vector<int> paz_;
    int egzaminas_;
    double galutinis_vid_;
    double galutinis_med_;

public:
    Studentas() : egzaminas_(0), galutinis_vid_(0.0), galutinis_med_(0.0) { };  
    Studentas(std::istream& is);
    ~Studentas() override;
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    inline const std::vector<int>& paz() const { return paz_; }
    inline int egz() const { return egzaminas_; } 
    inline double galutinis_vid() const {return galutinis_vid_; }
    inline double galutinis_med() const {return galutinis_med_; }

    std::istream& readStudent(std::istream&);
    void galBalas();
    void setPazymis(int paz) { paz_.push_back(paz); }
    void setEgzaminas(int egz) { egzaminas_ = egz; }
    void zmogus_info() const override;   
};

std::istream& operator>>(std::istream& is, Studentas& s);
std::ostream& operator<<(std::ostream& os, const Studentas& s);

bool compareVP(const Studentas& a, const Studentas& b);
bool compareEgzaminas(const Studentas& a, const Studentas& b);
bool compareGalBalas(const Studentas& a , const Studentas& b);

