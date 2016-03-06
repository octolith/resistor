#include "resistor.h"

/**
 * Ohmikus ellenállást megvalósitó osztály kipróbálása
 */

double Resistor::defR = 15000;          //defR statikus tag, ami azt jelenti, hogy nem példányosodik.
                                        //egyetlen egy példány van belőle, amit explicit módon létre kell hozni
                                        //kell a Resistor:: hogy tudjuk, hogy ennek a statikus tagjáról van szó

/// Kontstruktor.
/// Alapértelmezett értéket (defR) kap
Resistor::Resistor() : R(defR) {}       //Inicializáló lista használata. Konstans tag és referencia tag csak inicializáló listával inicializálható.
                                        //Érdemes a tagváltozókat is így inicializálni a felesleges műveletek elkerülése érdekében.
                                        //Csak konstruktorban lehet használni!

/// Kontstruktor.
/// @param r - ellenállás értéke [ohm]
Resistor::Resistor(double r) : R(r) {}  //Inicializáló listával

/// Default ellenállásérték beállítása
/// @param r - ellenállás értéke [ohm]
void Resistor::setDef(double r) {
	defR = r;
}

/// Két ellenállás soros kapcsolása.
/// @param r - ellenállás
/// @return  - eredõ ellenállás
Resistor Resistor::operator+(const Resistor& r) const{
    return Resistor(R + r.R);
}

/// Két ellenállás párhuzamos kapcsolása.
/// @param r - ellenállás
/// @return  - eredõ ellenállás
Resistor Resistor::operator%(const Resistor& r) const{
    return Resistor(1/(1/R+1/r.R));
}

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n - darabszám
/// @param r - ellenállás
/// @return  - eredõ ellenállás
Resistor operator*(int n, const Resistor& r){
    if(n<=0) throw "ZCH7OS";
    return Resistor(n*r.getR());        //azért kell a getR(), mert nem tagfüggvény, így a privát adattagot nem éri el
}
