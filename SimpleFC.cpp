//
// Created by berilbayram on 1.11.2019.
//

#include "SimpleFC.h"
using namespace std;

FC::FC() {
    noOfFilms = 0;
    films = new Film[noOfFilms];
}

FC::FC(const FC &fcToCopy) {
    noOfFilms = fcToCopy.noOfFilms;
    films = new Film[noOfFilms];
    for(unsigned int i = 0; i < noOfFilms; i++){
        films[i] = fcToCopy.films[i];
    }
}

FC::~FC(){
    delete[] films;
}

void FC::operator=(const FC &right) {
    noOfFilms = right.noOfFilms;
    films = new Film[noOfFilms];
    if ( &right != this ) {
        for (unsigned int i = 0; i < noOfFilms; i++){
            films[i] = right.films[i];
        }
    }
}

bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration){
    Film* filmsTemp = new Film[noOfFilms + 1];
    Film* tempFilm = new Film(fTitle,fDirector,fYear,fDuration);
    for(int i = 0; i < noOfFilms; i++){
        filmsTemp[i] = films[i];
    }
    filmsTemp[noOfFilms] = *tempFilm;

    for(unsigned int i = 0; i < noOfFilms; i++) {
        if (films[i].getTitle() == fTitle && films[i].getDirector() == fDirector ) {
            delete tempFilm;
            delete[] filmsTemp;
            return false;
        }
    }
    noOfFilms++;
    delete[] films;
    films = new Film[noOfFilms];
    for(unsigned int i = 0; i < noOfFilms; i++){
        films[i] = filmsTemp[i];
    }
    delete tempFilm;
    delete[] filmsTemp;
    return true;
}

bool FC::removeFilm(const string fTitle, const string fDirector){
    for(unsigned int i = 0; i < noOfFilms; i++ ){
        if(films[i].getTitle() == fTitle && films[i].getDirector() == fDirector){
            Film* delFilm = new Film("","",0,0);
            films[i] = *delFilm;
            Film* tempFilms = new Film[noOfFilms - 1];
            for(unsigned int i = 0; i < noOfFilms; i++){
                if (films[i].getTitle() != "" || films[i].getDirector() != ""){
                    tempFilms[i] = films[i];
                }
            }
            noOfFilms--;
            delete[] films;
            films = new Film[noOfFilms];
            for(unsigned int i = 0; i < noOfFilms; i++){
                films[i] = tempFilms[i];
            }
            delete delFilm;
            delete[] tempFilms;
            return true;
        }
    }
    return false;
}


unsigned int FC::getFilms(Film *&allFilms) const {
    allFilms = new Film[noOfFilms];
    for(int i = 0; i < noOfFilms; i++){
        allFilms[i] = films[i];
    }
    return noOfFilms;
}

