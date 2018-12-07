/**
*
*
*
*/

#include "nafta.hpp"
#include "rand.h"
#include "jaro.hpp"

// regeneracni hnojeni po zime, 90-100kg LAV hnojiva
void jaro::regenHnojeni(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;

	float davka = getRandInRange(90.0, 100.0);

	traktor.naftaHnojeni(naklady, pole, davka, naftaCelkem);

	float cena = getRandInRange(6.75, 7.35);

	*naklady = *naklady + (pole * cena * davka);
}

// produkcni hnojeni, 60kg DAM 390 hnojiva
void jaro::produkHnojeni(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;

	float davka = getRandInRange(60.0, 70.0);

	traktor.naftaHnojeni(naklady, pole, davka, naftaCelkem);

	float cena = getRandInRange(7.986, 8.41);

	*naklady = *naklady + (pole * cena * davka);
}

// ochrana proti krytonosci repkovemu, pokud se vyskytl
void jaro::krytonosecRepkovy(float* naklady, float pole, float* naftaCelkem){
	
	float vyskyt = getRandInRange(0.0, 1.0);

	if((vyskyt * 100) > 55.02)
		return;

	nafta traktor;

	traktor.naftaPostrik(naklady, pole, naftaCelkem);

	//float cena = getRandInRange(38, 47);

	*naklady = *naklady + (pole * 1020.0 * 0.6);
}

// regulator rustu, Caramba 1l/ha
void jaro::regulatorRustu(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;

	traktor.naftaPostrik(naklady, pole, naftaCelkem);

	//float cena = getRandInRange(38, 47);
	float davka = getRandInRange(0.8, 1.2);

	*naklady = *naklady + (pole * 1057.4 * davka);
}

// ochrana proti blyskackovi, pokud se vyskytl
void jaro::blyskacek(float* naklady, float pole, float* naftaCelkem){

	float vyskyt = getRandInRange(0.0, 1.0);

	if((vyskyt * 100) > 65.35)
		return;

	nafta traktor;

	traktor.naftaPostrik(naklady, pole, naftaCelkem);

	//float cena = getRandInRange(38, 47);

	*naklady = *naklady + (pole * 1472.0 * 0.15);
}

// aplikace listovych hnojiv, campofort special B hnojivo 10l/ha
void jaro::listovaHnojiva(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;

	traktor.naftaPostrik(naklady, pole, naftaCelkem);

	float cena = getRandInRange(38, 47);

	*naklady = *naklady + (pole * cena * 10.0);
}

// doladovaci davka dusiku, LAV 30kg/ha
void jaro::doladovaciDusik(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;

	float davka = getRandInRange(30.0, 40.0);

	traktor.naftaHnojeni(naklady, pole, davka, naftaCelkem);

	float cena = getRandInRange(6.75, 7.35);

	*naklady = *naklady + (pole * cena * davka);
}

// ochrana proti bejlomorce, pokud se silne vyskytla
void jaro::bejlomorka(float* naklady, float pole, float* naftaCelkem){
	float vyskyt = getRandInRange(0.0, 1.0);

	if((vyskyt * 100) > 11.83)
		return;

	nafta traktor;

	traktor.naftaPostrik(naklady, pole, naftaCelkem);

	//float cena = getRandInRange(38, 47);

	*naklady = *naklady + (pole * 6600.0 * 0.1);
}

// ochrana proti krytonosci sesulovemu
void jaro::krytonosecSesulovy(float* naklady, float pole, float* naftaCelkem){
	float vyskyt = getRandInRange(0.0, 1.0);

	if((vyskyt * 100) > 70.43)
		return;

	nafta traktor;

	traktor.naftaPostrik(naklady, pole, naftaCelkem);

	float davka = getRandInRange(0.125, 0.15);

	*naklady = *naklady + (pole * 1057.4 * davka);
}

// ochrana proti msicim pokud se silne vyskytly
void jaro::msice(float* naklady, float pole, float* naftaCelkem){
	float vyskyt = getRandInRange(0.0, 1.0);

	if((vyskyt * 100) > 12.4)
		return;

	nafta traktor;

	traktor.naftaPostrik(naklady, pole, naftaCelkem);

	//float cena = getRandInRange(38, 47);

	*naklady = *naklady + (pole * 4800.0 * 0.3);
}

void jaro::sklizen(float* naklady, float pole, float* naftaCelkem){
	nafta kombajn;
	kombajn.naftaSklizen(naklady, pole, naftaCelkem);
}