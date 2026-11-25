#include "basic_funkcijos.h"
#include "vector_funkcijos.h"
#include "template_funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>


void rusiavimasPV(std::vector<Studentas> &grupe){
    std::sort(grupe.begin(), grupe.end(), compareVP);
}

void rusiavimasG(std::vector<Studentas> &grupe){
    std::sort(grupe.begin(), grupe.end(), compareGalBalas);
}

void dalinti_studentus1(std::vector<Studentas> &grupe, std::vector<Studentas> &kietiakai, std::vector<Studentas> &vargsiukai){
    vargsiukai.reserve(grupe.size() / 2);
    kietiakai.reserve(grupe.size() / 2);
    for(auto &a : grupe){
        if (a.galutinis_vid() >= 5.0){
            kietiakai.push_back(a);
        }
        else {
            vargsiukai.push_back(a);
        }
    }
} 

void dalinti_studentus2(std::vector<Studentas> &grupe, std::vector<Studentas> &vargsiukai){
    vargsiukai.reserve(grupe.size() / 2); 
    while (grupe.back().galutinis_vid() < 5.0){
        vargsiukai.push_back(grupe.back());
        grupe.pop_back();
    }
} 

void dalinti_studentus3(std::vector<Studentas> &grupe, std::vector<Studentas> &vargsiukai){
      auto atrinkti = std::stable_partition(grupe.begin(), grupe.end(), [](const Studentas &s) {
        return s.galutinis_vid() >= 5.0;
    });

    vargsiukai.reserve(grupe.size() / 2);
    vargsiukai.assign(std::make_move_iterator(atrinkti), std::make_move_iterator(grupe.end()));
    grupe.erase(atrinkti, grupe.end());
}

