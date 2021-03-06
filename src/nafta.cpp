/*
*
*
*
*/

#include "nafta.hpp"
#include "rand.h"

// spotreba nafty pri seti
void nafta::naftaSeti(float* naklady, float pole, float* naftaCelkem){
	// spotreba l/ha
	float spotreba = getRandInRange(7.8, 8.3);

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}

// spotreba nafty pri hnojeni
void nafta::naftaHnojeni(float* naklady, float pole, int davka, float* naftaCelkem){
	float spotreba;
	if(davka <= 300)
		spotreba = getRandInRange(1.8, 2.2);

	else if(davka > 300 && davka < 500)
		spotreba = getRandInRange(2.3, 2.5);

	else
		spotreba = getRandInRange(2.6, 3.0);

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}	

// spotreba nafty pri postriku pole
void nafta::naftaPostrik(float* naklady, float pole, float* naftaCelkem){
	float spotreba = getRandInRange(2.5, 2.8);

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}	

// spotreba nafty pri sberu slamy predplodiny
void nafta::naftaSlama(float* naklady, float pole, float* naftaCelkem){
	float spotreba = getRandInRange(1.3, 1.6);

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}

// spotreba nafty pri sklizni repky
void nafta::naftaSklizen(float* naklady, float pole, float* naftaCelkem){
	float spotreba = getRandInRange(14.9, 15.5);

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}

// spotreba nafty u podmitky radlicnym podmitacem
void nafta::naftaRadlicny(float* naklady, float pole, float* naftaCelkem){
	float spotreba = getRandInRange(11.3, 11.5);

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}

// spotreba nafty u podmimtky talirovym podmitacem	
void nafta::naftaTalirovy(float* naklady, float pole, float* naftaCelkem){
	float spotreba = getRandInRange(5.8, 6.1);

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}

// spotreba nafty pri orbe
void nafta::naftaOrba(float* naklady, float pole, float* naftaCelkem){
	float spotreba = getRandInRange(18.1, 18.5);;

	float cenaZaAkci = spotreba * pole * getCenaNafty();

	*naftaCelkem = *naftaCelkem + cenaZaAkci;

	*naklady = *naklady + cenaZaAkci;
}

float nafta::getCenaNafty(){
	return getRandInRange(28.35, 33.32);
}
