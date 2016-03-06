#ifndef RESISTOR_H
#define RESISTOR_H

/**
 * Ohmikus ellen�ll�s
 */
class Resistor {
    double R;              	// az ellen�ll�s �rt�ke ohmban
    static double defR;  	// ellen�ll�s alap�rtelmezett �rt�ke ohmban
public:

    /// Kontstruktor.
    /// Alap�rtelmezett �rt�ket (defR) kap
    Resistor();

    /// Kontstruktor.
    /// @param r - ellen�ll�s �rt�ke [ohm]
    Resistor(double r);

    /// Default ellen�ll�s�rt�k be�ll�t�sa
    /// @param r - ellen�ll�s �rt�ke [ohm]
    static void setDef(double r);

    /// Ellen�ll�s �rt�k�nek lek�rdez�se.
    /// @return - ellen�ll�s �rt�ke [ohm]
    double getR() const {
        return R;
    }

    /// K�t ellen�ll�s soros kapcsol�sa.
    /// @param r - ellen�ll�s 
    /// @return  - ered� ellen�ll�s 
    Resistor operator+(const Resistor& r) const;

    /// K�t ellen�ll�s p�rhuzamos kapcsol�sa.
    /// @param r - ellen�ll�s 
    /// @return  - ered� ellen�ll�s
    Resistor operator%(const Resistor& r) const;

};

/// T�bbsz�r�s: n darab egyforma r ellen�ll�s �sszege (soros kapcsol�sa).
/// @param n - darabsz�m
/// @param r - ellen�ll�s 
/// @return  - ered� ellen�ll�s
Resistor operator*(int n, const Resistor& r);

#endif

