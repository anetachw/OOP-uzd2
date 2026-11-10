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


void automatine_ivestis(std::vector<Studentas> &grupe, std::mt19937 &mt){
    int stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 1000000);
    grupe.reserve(grupe.size() + stud_kiekis);

    int nd_kiekis = ar_skaicius("Įveskite kiek namų darbų pažymių norite sugeneruoti: ", 1, 10); 

    for(int j=0; j < stud_kiekis; j++){
        Studentas tempStudentas;
        //tempStudentas.paz().reserve(nd_kiekis);
        tempStudentas.vardas() = "Vardas" + std::to_string(j + 1);
        tempStudentas.pavarde() = "Pavarde" + std::to_string(j + 1);
        generuoti_paz(tempStudentas, nd_kiekis, mt);
        grupe.push_back(tempStudentas);
    }
};

void nuskaityti_faila(std::vector<Studentas> &grupe, const std::string failoPavadinimas){
    std::ifstream f(failoPavadinimas, std::ios::ate);

    if(!f.is_open()){
        std::cout << "Nepavyko atidaryti failo: " << failoPavadinimas << '\n';
        return;
    }

    std::streamsize file_size = f.tellg();
    f.seekg(0, std::ios::beg); 
    size_t eil_sk = file_size / 134;
    grupe.reserve(grupe.size() + eil_sk);
    
    std::string eilute;
    std::getline (f, eilute);

    std::stringstream ss;
    while(std::getline(f, eilute)){
        if (eilute.empty()) continue;
        ss.str(eilute);
        ss.clear();

        std::istringstream ss(eilute);
        Studentas tempStudentas;
        tempStudentas.readStudent(ss);

        grupe.push_back(tempStudentas);
    }

    f.close();
};

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
            return a.galBalas(vidurkis) > a.galBalas(vidurkis);
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

