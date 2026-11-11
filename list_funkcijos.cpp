#include "basic_funkcijos.h"
#include "list_funkcijos.h"
#include "template_funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>


void rusiavimasPV(std::list<Studentas> &grupe){
    grupe.sort(compareVP);
};

void rusiavimasG(std::list<Studentas> &grupe){
    grupe.sort(compareGalBalas);
};

void dalinti_studentus1(std::list<Studentas> &grupe, std::list<Studentas> &kietiakai, std::list<Studentas> &vargsiukai){
    for (auto it = grupe.begin(); it != grupe.end(); it++){
        if ((*it).galBalas(vidurkis) >= 5.0){
            kietiakai.push_back(*it);
        }
        else {
            vargsiukai.push_back(*it);
        }
    }
}; 
void dalinti_studentus2(std::list<Studentas> &grupe, std::list<Studentas> &vargsiukai){
    for (auto it = grupe.end(); it != grupe.begin(); ){
        --it;

        if ((*it).galBalas(vidurkis) < 5.0){
            vargsiukai.push_back(*it);
            it = grupe.erase(it);
        }
        else { 
          continue;
        }
    }
};

void dalinti_studentus3(std::list<Studentas> &grupe, std::list<Studentas> &vargsiukai){
    for (auto it = grupe.begin(); it != grupe.end(); ){
        if ((*it).galBalas(vidurkis) < 5.0){
            vargsiukai.splice(vargsiukai.end(), grupe, it++);
        }
        else {
            ++it;
        }
    }
}; 