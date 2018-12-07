class jaro
{
public:
	
	// regeneracni hnojeni po zime, 90-100kg LAV hnojiva
	void regenHnojeni(float* naklady, float pole, float* naftaCelkem);	

	// produkcni hnojeni, 60kg DAM 390 hnojiva
	void produkHnojeni(float* naklady, float pole, float* naftaCelkem);

	// ochrana proti krytonosci repkovemu, pokud se vyskytl
	void krytonosecRepkovy(float* naklady, float pole, float* naftaCelkem);

	// regulator rustu, Caramba 1l/ha
	void regulatorRustu(float* naklady, float pole, float* naftaCelkem);

	// ochrana proti blyskackovi, pokud se vyskytl
	void blyskacek(float* naklady, float pole, float* naftaCelkem);

	// aplikace listovych hnojiv, campofort special B hnojivo 10l/ha
	void listovaHnojiva(float* naklady, float pole, float* naftaCelkem);

	// doladovaci davka dusiku, LAV 30kg/ha
	void doladovaciDusik(float* naklady, float pole, float* naftaCelkem);

	// ochrana proti bejlomorce, pokud se silne vyskytla
	void bejlomorka(float* naklady, float pole, float* naftaCelkem);

	// ochrana proti krytonosci sesulovemu
	void krytonosecSesulovy(float* naklady, float pole, float* naftaCelkem);

	// ochrana proti msicim pokud se silne vyskytly
	void msice(float* naklady, float pole, float* naftaCelkem);

	// sklizen
	void sklizen(float* naklady, float pole, float* naftaCelkem);

};