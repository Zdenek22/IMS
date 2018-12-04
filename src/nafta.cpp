/*
*
*
*
*/

// spotreba nafty pri seti
void naftaSeti(float* naklady, float pole){
	// spotreba l/ha
	float spotreba = 8.0;

	*naklady = spotreba * pole * getCenaNafty();
}

// spotreba nafty pri hnojeni
void naftaHnojeni(float* naklady, float pole, int davka){
	float spotreba;
	if(davka <= 300)
		spotreba = 1.9;

	else if(davka > 300 && davka < 500)
		spotreba = 2.4;

	else
		spotreba = 3.0;


	*naklady = spotreba * pole * getCenaNafty();
}	

// spotreba nafty pri postriku pole
void naftaPostrik(float* naklady, float pole){
	float spotreba = 2.5;

	*naklady = spotreba * pole * getCenaNafty();
}	

// spotreba nafty pri sberu slamy predplodiny
void naftaSlama(float* naklady, float pole){
	float spotreba = 1.3;

	*naklady = spotreba * pole * getCenaNafty();
}

// spotreba nafty pri sklizni repky
void naftaSklizen(float* naklady, float pole){
	float spotreba = 15.0;

	*naklady = spotreba * pole * getCenaNafty();
}

// spotreba nafty u podmitky radlicnym podmitacem
void naftaRadlicny(float* naklady, float pole){
	float spotreba = 11.5;

	*naklady = spotreba * pole * getCenaNafty();
}

// spotreba nafty u podmimtky talirovym podmitacem	
void naftaTalirovy(float* naklady, float pole){
	float spotreba = 5.9;

	*naklady = spotreba * pole * getCenaNafty();
}

// spotreba nafty pri orbe
void naftaOrba(float* naklady, float pole){
	float spotreba = 18.0;

	*naklady = spotreba * pole * getCenaNafty();
}
