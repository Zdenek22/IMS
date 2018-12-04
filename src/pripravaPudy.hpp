class pripravaPudy
{
public:

	// aplikace hnojiv
	void aplikaceHnojiv(float* naklady, float pole);

	// klasicka priprava pudy, radlicne podmitace + orba
	void klasickaPriprava(float* naklady, float pole);

	// minimalizacni priprava pudy, talirove podmitace
	void minimalizacniPriprava(float* naklady, float pole);

	// seti
	void seti(float* naklady, float pole);

	// uklid slamy
	void uklid(float* naklady, float pole);

};