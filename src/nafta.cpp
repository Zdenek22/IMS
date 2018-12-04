/*
*
*
*
*/

// spotreba nafty pri seti
void nafta::naftaSeti(float* naklady, float pole){
	// spotreba l/ha
	float spotreba = 8.0;

	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}

// spotreba nafty pri hnojeni
void nafta::naftaHnojeni(float* naklady, float pole, int davka){
	float spotreba;
	if(davka <= 300)
		spotreba = 1.9;

	else if(davka > 300 && davka < 500)
		spotreba = 2.4;

	else
		spotreba = 3.0;


	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}	

// spotreba nafty pri postriku pole
void nafta::naftaPostrik(float* naklady, float pole){
	float spotreba = 2.5;

	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}	

// spotreba nafty pri sberu slamy predplodiny
void nafta::naftaSlama(float* naklady, float pole){
	float spotreba = 1.3;

	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}

// spotreba nafty pri sklizni repky
void nafta::naftaSklizen(float* naklady, float pole){
	float spotreba = 15.0;

	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}

// spotreba nafty u podmitky radlicnym podmitacem
void nafta::naftaRadlicny(float* naklady, float pole){
	float spotreba = 11.5;

	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}

// spotreba nafty u podmimtky talirovym podmitacem	
void nafta::naftaTalirovy(float* naklady, float pole){
	float spotreba = 5.9;

	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}

// spotreba nafty pri orbe
void nafta::naftaOrba(float* naklady, float pole){
	float spotreba = 18.0;

	*naklady = *naklady + (spotreba * pole * getCenaNafty());
}
