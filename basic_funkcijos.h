#pragma once 

#include "studentas.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <random>
#include <chrono>
#include <vector>


void generuoti_faila(std::string failoPavadinimas, int stud_kiekis, int nd_kiekis, std::mt19937 &mt);

bool failas_egzistuoja(const std::string &failoPavadinimas);

int ar_skaicius(std::string tekstas, int min, int max);

void rodyti_meniu(); 

void rodyti_konteineri();

double vidurkis(std::vector<int> paz);

double mediana(std::vector<int> paz);


