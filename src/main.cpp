#include <iostream>
#include <stdlib.h> 
#include <time.h>


#include "pripravaPudy.hpp"
#include "jaro.hpp"
#include "podzim.h"

int main(int argc, char** argv){
	
	srand(time(NULL));
	float naklady = 0.0;
	float tmp;
	float pole = std::stof(argv[1]);
	int technologie = std::atoi(argv[2]);

	pripravaPudy priprava;

	std::cout<<"##############################################"<<std::endl << "##" << std::endl << "##" << std::endl;

	tmp = naklady;
	priprava.uklid(&naklady, pole);
	std::cout << "##\tUklid slamy\t\tcelkove naklady" <<std::endl;
	std::cout << "##\t"<<(naklady - tmp)<< " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;

	tmp = naklady;
	priprava.aplikaceHnojiv(&naklady, pole);
	std::cout << "##\tAplikace hnojiv"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;

	tmp = naklady;
	// vyber technologie, 1 - klasicka, 2 - minimalizacni, 3 - bezorebna
	if(technologie == 1){
		priprava.klasickaPriprava(&naklady, pole);
		std::cout << "##\tKlasicke pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	}
	else if(technologie == 2){
		priprava.minimalizacniPriprava(&naklady, pole);
		std::cout << "##\tMinimalizacni pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	}
	else{
		std::cout << "##\tBezorebne pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	}

	tmp = naklady;
	priprava.seti(&naklady, pole);
	std::cout << "##\tVysazeni semen repky"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	std::cout<<"##############################################\n##"<<std::endl;


	// PODZMIMNI OSETROVANI
	tmp = naklady;
	aplikaceHerbicidu(&naklady, pole);
	std::cout << "##\tAplikace herbicidu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	krytonosecSesulovy(&naklady, pole);
	std::cout << "##\tPostrik proti krytonosci sesulovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	drepcik(&naklady, pole);
	std::cout << "##\tPostrik proti drepcikovi"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	hrabosi(&naklady, pole);
	std::cout << "##\tPostrik proti hrabosum"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	regRustu(&naklady, pole);
	std::cout << "##\tAplikace regulatoru vzrustu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	pilatka(&naklady, pole);
	std::cout << "##\tPostrik proti pilatkam"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	



	std::cout<<"##############################################\n##"<<std::endl;

	// JARNI OSETROVANI
	jaro jarniOsetreni;

	tmp = naklady;
	jarniOsetreni.regenHnojeni(&naklady, pole);
	std::cout << "##\tRegeneracni hnojeni"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	jarniOsetreni.produkHnojeni(&naklady, pole);
	std::cout << "##\tProdukcni hnojeni"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;

	tmp = naklady;
	jarniOsetreni.krytonosecRepkovy(&naklady, pole);
	std::cout << "##\tOchrana proti krytonosci repkovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	jarniOsetreni.regulatorRustu(&naklady, pole);
	std::cout << "##\tAplikace regulatoru rustu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	jarniOsetreni.blyskacek(&naklady, pole);
	std::cout << "##\tOchrana proti blyskackovi"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;

	tmp = naklady;
	jarniOsetreni.listovaHnojiva(&naklady, pole);
	std::cout << "##\tAplikace listovych hnojiv"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	jarniOsetreni.doladovaciDusik(&naklady, pole);
	std::cout << "##\tDoladovaci davka dusiku"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	jarniOsetreni.bejlomorka(&naklady, pole);
	std::cout << "##\tOchrana proti bejlomorce"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	jarniOsetreni.krytonosecSesulovy(&naklady, pole);
	std::cout << "##\tOchrana proti krytonosci sesulovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	tmp = naklady;
	jarniOsetreni.msice(&naklady, pole);
	std::cout << "##\tOchrana proti msicim"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	return 0;
}
