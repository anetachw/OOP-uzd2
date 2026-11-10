#pragma once 

#include "studentas.h"
#include <string>
#include <random>


void automatine_ivestis(std::vector<Studentas> &grupe, std::mt19937 &mt);

void nuskaityti_faila(std::vector<Studentas> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::vector<Studentas> &grupe);

void rusiavimasG(std::vector<Studentas> &grupe);

void dalinti_studentus1(std::vector<Studentas> &grupe, std::vector<Studentas> &kietiakai, std::vector<Studentas> &vargsiukai);

void dalinti_studentus2(std::vector<Studentas> &grupe, std::vector<Studentas> &vargsiukai);

void dalinti_studentus3(std::vector<Studentas> &grupe, std::vector<Studentas> &vargsiukai);

