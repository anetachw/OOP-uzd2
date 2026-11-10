#pragma once 

#include "studentas.h"
#include <string>
#include <list>
#include <random>


void automatine_ivestis(std::list<Studentas> &grupe, std::mt19937 &mt);

void nuskaityti_faila(std::list<Studentas> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::list<Studentas> &grupe);

void rusiavimasG(std::list<Studentas> &grupe);

void dalinti_studentus1(std::list<Studentas> &grupe, std::list<Studentas> &kietiakai, std::list<Studentas> &vargsiukai);

void dalinti_studentus2(std::list<Studentas> &grupe, std::list<Studentas> &vargsiukai);

void dalinti_studentus3(std::list<Studentas> &grupe, std::list<Studentas> &vargsiukai);