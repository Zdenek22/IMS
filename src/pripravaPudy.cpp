/*
*
*
*
*/

#include "pripravaPudy.hpp"
#include "nafta.hpp"
#include "rand.h"

void pripravaPudy::aplikaceHnojiv(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;

	// nafta za aplikaci siranu draselneho
	traktor.naftaHnojeni(naklady, pole, 320, naftaCelkem);

	// cena za hnojivo za siran draselny 18 271 - 22 886 Kc/t
	float cenaSiran = getRandInRange(18.271, 22.886);

	// pripocteni k nakladum, cena siranu * davka siranu * velikost pole
	*naklady = *naklady + (cenaSiran * 320 * pole);

	// cena za hnojivo Kierestan, 8450 - 11 960 KC/t
	float cenaKierestan = getRandInRange(8.450, 11.960);

	*naklady = *naklady + (cenaKierestan * 200 * pole);
}


void pripravaPudy::klasickaPriprava(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;
	// nafta za pripravu radlicnym podmitacem
	traktor.naftaRadlicny(naklady,pole, naftaCelkem);

	// nafta za orbu
	traktor.naftaOrba(naklady, pole, naftaCelkem);

}

void pripravaPudy::minimalizacniPriprava(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;
	// nafta za pripravu talirovymi podmitaci
	traktor.naftaTalirovy(naklady, pole, naftaCelkem);
}

void pripravaPudy::seti(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;
	// nafta za seti
	traktor.naftaSeti(naklady, pole, naftaCelkem);

	// cena za osivo, 2420 - 2800 Kc/VJ, VJ = vysevni jednotka -> pocet semen vhodnych na vysazeni jednoho hektaru
	float cenaOsivo = getRandInRange(2400.0, 2873.0);

	*naklady = *naklady + (cenaOsivo * pole);

}

void pripravaPudy::uklid(float* naklady, float pole, float* naftaCelkem){
	nafta traktor;
	traktor.naftaSlama(naklady, pole, naftaCelkem);
}