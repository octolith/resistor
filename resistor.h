#ifndef RESISTOR_H
#define RESISTOR_H

/**
 * Ohmikus ellenállás
 */
class Resistor {
    double R;              	// az ellenállás értéke ohmban
    static double defR;  	// ellenállás alapértelmezett értéke ohmban
public:

    /// Kontstruktor.
    /// Alapértelmezett értéket (defR) kap
    Resistor();

    /// Kontstruktor.
    /// @param r - ellenállás értéke [ohm]
    Resistor(double r);

    /// Default ellenállásérték beállítása
    /// @param r - ellenállás értéke [ohm]
    static void setDef(double r);

    /// Ellenállás értékének lekérdezése.
    /// @return - ellenállás értéke [ohm]
    double getR() const {
        return R;
    }

    /// Két ellenállás soros kapcsolása.
    /// @param r - ellenállás 
    /// @return  - eredő ellenállás 
    Resistor operator+(const Resistor& r) const;

    /// Két ellenállás párhuzamos kapcsolása.
    /// @param r - ellenállás 
    /// @return  - eredő ellenállás
    Resistor operator%(const Resistor& r) const;

};

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n - darabszám
/// @param r - ellenállás 
/// @return  - eredő ellenállás
Resistor operator*(int n, const Resistor& r);

#endif

