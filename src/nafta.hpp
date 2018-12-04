class nafta
{

private:
	float cenaNafty = 30.90;


public:
	nafta();
	~nafta();

	float getCenaNafty(return cenaNafty;);

	// spotreba nafty pri seti
	void naftaSeti(float* naklady, float pole);

	// spotreba nafty pri hnojeni
	void naftaHnojeni(float* naklady, float pole, int davka);

	// spotreba nafty pri postriku pole
	void naftaPostrik(float* naklady, float pole);

	// spotreba nafty pri sberu slamy predplodiny
	void naftaSlama(float* naklady, float pole);

	// spotreba nafty pri sklizni repky
	void naftaSklizen(float* naklady, float pole);

	// spotreba nafty u podmitky radlicnym podmitacem
	void naftaRadlicny(float* naklady, float pole);

	// spotreba nafty u podmimtky talirovym podmitacem	
	void naftaTalirovy(float* naklady, float pole);

	// spotreba nafty pri orbe
	void naftaOrba(float* naklady, float pole);
};