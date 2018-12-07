class pripravaPudy
{
public:

	// aplikace hnojiv
	void aplikaceHnojiv(float* naklady, float pole, float* nafta);

	// klasicka priprava pudy, radlicne podmitace + orba
	void klasickaPriprava(float* naklady, float pole, float* nafta);

	// minimalizacni priprava pudy, talirove podmitace
	void minimalizacniPriprava(float* naklady, float pole, float* nafta);

	// seti
	void seti(float* naklady, float pole, float* nafta);

	// uklid slamy
	void uklid(float* naklady, float pole, float* nafta);

};