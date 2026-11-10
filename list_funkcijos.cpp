#include "basic_funkcijos.h"
#include "list_funkcijos.h"
#include "template_funkcijos.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>


void automatine_ivestis(std::list<Studentas> &grupe, std::mt19937 &mt){
    int stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 1000000);
    int nd_kiekis = ar_skaicius("Įveskite kiek namų darbų pažymių norite sugeneruoti: ", 1, 10); 

    for(int j=0; j < stud_kiekis; j++){
        Studentas tempStudentas;
        tempStudentas.vardas() = "Vardas" + std::to_string(j + 1);
        tempStudentas.pavarde() = "Pavarde" + std::to_string(j + 1);
        generuoti_paz(tempStudentas, nd_kiekis, mt);
        grupe.push_back(tempStudentas);
    }

};

void nuskaityti_faila(std::list<Studentas> &grupe, const std::string failoPavadinimas){
    std::ifstream f(failoPavadinimas, std::ios::ate);

    if(!f.is_open()){
        std::cout << "Nepavyko atidaryti failo: " << failoPavadinimas << '\n';
        return;
    };
    
    std::string eilute;
    std::getline (f, eilute);

    while(f){
        Studentas tempStudentas; 
        if (tempStudentas.readStudent(f)){
            grupe.push_back(tempStudentas);
        } else{
            break;
        }
    }

    f.close();
};

void rusiavimasPV(std::list<Studentas> &grupe){
    grupe.sort([](const Studentas &a, const Studentas &b){
        if (a.pavarde() != b.pavarde()){
            return a.pavarde() < b.pavarde();
        }
        return a.vardas() < b.vardas();
    });
};

void rusiavimasG(std::list<Studentas> &grupe){
    grupe.sort([](const Studentas &a, const Studentas &b){
            return a.galBalas(vidurkis) > b.galBalas(vidurkis);
    });
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