// studentu valdymo programa
#include <iostream>
#include "studentas.h"
#include "basic_funkcijos.h"
#include "vector_funkcijos.h"
#include "list_funkcijos.h"
#include "template_funkcijos.h"
#include <list>


int main(){
    std::random_device rd;
    std::mt19937 mt(rd());

    rodyti_konteineri();
    int konteineris = ar_skaicius("\nPasirinkite konteinerį (1-2): ", 1, 2);
    
    if (konteineris == 1){
        paleisti_programa<std::vector<Studentas>>(mt);
    }
    else if (konteineris == 2){
        paleisti_programa<std::list<Studentas>>(mt);
    }
}