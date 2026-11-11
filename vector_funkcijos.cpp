#include "basic_funkcijos.h"
#include "vector_funkcijos.h"
#include "template_funkcijos.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>


void rusiavimasPV(std::vector<Studentas> &grupe){
    std::sort(grupe.begin(), grupe.end(),
        [](const Studentas &a, const Studentas &b){
            if (a.pavarde() != b.pavarde()){
                return a.pavarde() < b.pavarde();
            }
            return a.vardas() < b.vardas();
    });
};

void rusiavimasG(std::vector<Studentas> &grupe){
    std::sort(grupe.begin(), grupe.end(),
        [](const Studentas &a, const Studentas &b){
            return a.galBalas(vidurkis) > b.galBalas(vidurkis);
    });
};

void dalinti_studentus1(std::vector<Studentas> &grupe, std::vector<Studentas> &kietiakai, std::vector<Studentas> &vargsiukai){
    vargsiukai.reserve(grupe.size() / 2);
    kietiakai.reserve(grupe.size() / 2);
    for (auto it = grupe.begin(); it != grupe.end(); ++it){
        if ((*it).galBalas(vidurkis) >= 5.0){
            kietiakai.push_back(*it);
        }
        else {
            vargsiukai.push_back(*it);
        }
    }
}; 


void dalinti_studentus2(std::vector<Studentas> &grupe, std::vector<Studentas> &vargsiukai){
    vargsiukai.reserve(grupe.size() / 2);    
    for (auto it = grupe.end(); it != grupe.begin(); ){
        --it;

        if ((*it).galBalas(vidurkis) < 5.0){
            vargsiukai.push_back(*it);
            grupe.erase(it);
        }
        else { 
            continue;
        }
    }
}; 

void dalinti_studentus3(std::vector<Studentas> &grupe, std::vector<Studentas> &vargsiukai){
      auto atrinkti = std::stable_partition(grupe.begin(), grupe.end(), [](const Studentas &s) {
        return s.galBalas(vidurkis) >= 5.0;
    });

    vargsiukai.reserve(grupe.size() / 2);
    vargsiukai.assign(std::make_move_iterator(atrinkti), std::make_move_iterator(grupe.end()));
    grupe.erase(atrinkti, grupe.end());
};

