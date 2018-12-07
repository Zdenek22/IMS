#include <stdio.h>
#include "nafta.hpp"
#include "podzim.h"
#include "rand.h"

#define TERIDOX_VAL			1126.0
#define COMMAND_36_VAL		4385.0
#define DECIS_MEGA_VAL		1472.0
#define KARATE_ZENON_VAL	2341.0
#define STUTOX_VAL			181.5
#define CCC_VAL				121.0
#define CARAMBA_VAL			1057.4
#define NURELLE_VAL			1020.0

void aplikaceHerbicidu(float* naklady, float pole, float* naftaCelkem) {
	nafta Nafta;
	float tmp = *naklady;

	//aplikace Teridoxu
	float teridox = pole * getRandInRange(1.5, 2.0)* TERIDOX_VAL;
	//aplikace Commandu
	float command = pole * getRandInRange(0.15, 0.25) * COMMAND_36_VAL;
	*naklady += teridox + command;
	//pripocteni ceny nafty
	Nafta.naftaPostrik(naklady, pole, naftaCelkem);

	//printf(" 6. Aplikace herbicidu. Naklady: %.2fKc.", (*naklady - tmp));
}

void krytonosecSesulovy(float* naklady, float pole, float* naftaCelkem) {
	nafta Nafta;
	float tmp = *naklady;
	float chance = getRandInRange(0.0, 1.0);

	if (chance < 0.7043) {
		//aplikace Teridoxu
		float decis = pole * getRandInRange(0.1, 0.15)* DECIS_MEGA_VAL;
		*naklady += decis;
		//pripocteni ceny nafty
		Nafta.naftaPostrik(naklady, pole, naftaCelkem);
		//printf(" 7. Postrik proti krytonosci sesulovemu. Naklady: %.2fKc. Krytonosec se OBJEVIL.", (*naklady - tmp));
	}
}

void drepcik(float* naklady, float pole, float* naftaCelkem) {
	nafta Nafta;
	float tmp = *naklady;
	float chance = getRandInRange(0.0, 1.0);

	if (chance < 0.5358) {

		float karate = pole * getRandInRange(0.1, 0.15)* KARATE_ZENON_VAL;
		*naklady += karate;
		//pripocteni ceny nafty
		Nafta.naftaPostrik(naklady, pole, naftaCelkem);
		//printf(" 8. Postrik proti drepcikovi. Naklady: %.2fKc. Drepcik se OBJEVIL.", (*naklady - tmp));
	}
}

void hrabosi(float* naklady, float pole, float* naftaCelkem) {
	nafta Nafta;
	float tmp = *naklady;
	float chance = getRandInRange(0.0, 1.0);

	if (chance < 0.6926) {

		float stutox = pole * getRandInRange(5.0, 10.0)* STUTOX_VAL;
		*naklady += stutox;
		//pripocteni ceny nafty
		Nafta.naftaPostrik(naklady, pole, naftaCelkem);
		//printf(" 9. Postrik proti hrabosum. Naklady: %.2fKc. Hrabosi se OBJEVILI.", (*naklady - tmp));
	}
}

void regRustu(float* naklady, float pole, float* naftaCelkem) {
	nafta Nafta;
	float tmp = *naklady;

	float ccc = pole * 2.0 * CCC_VAL;
	float caramba = pole * 0.5 * CARAMBA_VAL;
	*naklady += ccc + caramba;
	//pripocteni ceny nafty
	Nafta.naftaPostrik(naklady, pole, naftaCelkem);
	//printf("10. Aplikace regulatoru vzrustu. Naklady: %.2fKc. ", (*naklady - tmp));
}

void pilatka(float* naklady, float pole, float* naftaCelkem) {
	nafta Nafta;
	float tmp = *naklady;
	float chance = getRandInRange(0.0, 1.0);

	if (chance < 0.6926) {
		float nurelle = pole * 0.6* NURELLE_VAL;
		*naklady += nurelle;
		//pripocteni ceny nafty
		Nafta.naftaPostrik(naklady, pole, naftaCelkem);
		//printf("11. Postrik proti pilatkam. Naklady: %.2fKc. Pilatky se OBJEVILI.", (*naklady - tmp));
	}
}