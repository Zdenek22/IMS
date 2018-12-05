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
	float hnojivoCelkem = 0.0;
	float postrikyCelkem = 0.0;
	float regulatoryCelkem = 0.0;
	float herbicidyCelkem = 0.0;
	float pripravaCelkem = 0.0;
	

	pripravaPudy priprava;
	
	std::cout<<"\n\n############### PRIPRAVA PUDY ##################"<<std::endl << "##" << std::endl << "##" << std::endl;

	tmp = naklady;
	priprava.uklid(&naklady, pole);
	std::cout << "##\tUklid slamy\t\tcelkove naklady" <<std::endl;
	std::cout << "##\t"<<(naklady - tmp)<< " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	pripravaCelkem = pripravaCelkem + (naklady - tmp);

	tmp = naklady;
	priprava.aplikaceHnojiv(&naklady, pole);
	std::cout << "##\tAplikace hnojiv"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp);

	tmp = naklady;
	// vyber technologie, 1 - klasicka, 2 - minimalizacni, 3 - bezorebna
	if(technologie == 1){
		priprava.klasickaPriprava(&naklady, pole);
		std::cout << "##\tKlasicke pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
		pripravaCelkem = pripravaCelkem + (naklady - tmp);
	}
	else if(technologie == 2){
		priprava.minimalizacniPriprava(&naklady, pole);
		std::cout << "##\tMinimalizacni pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
		pripravaCelkem = pripravaCelkem + (naklady - tmp);
	}
	else{
		std::cout << "##\tBezorebne pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
		pripravaCelkem = pripravaCelkem + (naklady - tmp);
	}

	tmp = naklady;
	priprava.seti(&naklady, pole);
	std::cout << "##\tVysazeni semen repky"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	pripravaCelkem = pripravaCelkem + (naklady - tmp);	


	std::cout<<"################### PODZIM #####################\n##"<<std::endl;

	// PODZMIMNI OSETROVANI
	tmp = naklady;
	aplikaceHerbicidu(&naklady, pole);
	std::cout << "##\tAplikace herbicidu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	herbicidyCelkem = herbicidyCelkem + (naklady - tmp);	

	tmp = naklady;
	krytonosecSesulovy(&naklady, pole);
	std::cout << "##\tPostrik proti krytonosci sesulovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp);

	tmp = naklady;
	drepcik(&naklady, pole);
	std::cout << "##\tPostrik proti drepcikovi"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp);	

	tmp = naklady;
	hrabosi(&naklady, pole);
	std::cout << "##\tPostrik proti hrabosum"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp);	

	tmp = naklady;
	regRustu(&naklady, pole);
	std::cout << "##\tAplikace regulatoru vzrustu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	regulatoryCelkem = regulatoryCelkem + (naklady - tmp);

	tmp = naklady;
	pilatka(&naklady, pole);
	std::cout << "##\tPostrik proti pilatkam"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp);


	std::cout<<"################### JARO #######################\n##"<<std::endl;

	// JARNI OSETROVANI
	jaro jarniOsetreni;

	tmp = naklady;
	jarniOsetreni.regenHnojeni(&naklady, pole);
	std::cout << "##\tRegeneracni hnojeni"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp);	

	tmp = naklady;
	jarniOsetreni.produkHnojeni(&naklady, pole);
	std::cout << "##\tProdukcni hnojeni"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp);

	tmp = naklady;
	jarniOsetreni.krytonosecRepkovy(&naklady, pole);
	std::cout << "##\tOchrana proti krytonosci repkovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp);	

	tmp = naklady;
	jarniOsetreni.regulatorRustu(&naklady, pole);
	std::cout << "##\tAplikace regulatoru rustu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	regulatoryCelkem = regulatoryCelkem + (naklady - tmp);

	tmp = naklady;
	jarniOsetreni.blyskacek(&naklady, pole);
	std::cout << "##\tOchrana proti blyskackovi"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp);

	tmp = naklady;
	jarniOsetreni.listovaHnojiva(&naklady, pole);
	std::cout << "##\tAplikace listovych hnojiv"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp);

	tmp = naklady;
	jarniOsetreni.doladovaciDusik(&naklady, pole);
	std::cout << "##\tDoladovaci davka dusiku"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp);

	tmp = naklady;
	jarniOsetreni.bejlomorka(&naklady, pole);
	std::cout << "##\tOchrana proti bejlomorce"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp);	

	tmp = naklady;
	jarniOsetreni.krytonosecSesulovy(&naklady, pole);
	std::cout << "##\tOchrana proti krytonosci sesulovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp);

	tmp = naklady;
	jarniOsetreni.msice(&naklady, pole);
	std::cout << "##\tOchrana proti msicim"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp);

	tmp = naklady;
	jarniOsetreni.sklizen(&naklady, pole);
	std::cout << "##\tSklizen"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	
	std::cout<<"############## CELKOVE HODNOTY #################\n##"<<std::endl;
	std::cout << "##\tPriprava + seti\t\t"<< pripravaCelkem << " Kc"<<std::endl;
	std::cout << "##\tHnojivo\t\t\t"<< hnojivoCelkem << " Kc"<<std::endl;
	std::cout << "##\tOchrana proti skudcum\t"<< postrikyCelkem << " Kc"<<std::endl;
	std::cout << "##\tRegulatory\t\t"<< regulatoryCelkem << " Kc"<<std::endl;
	std::cout << "##\tHerbicidy\t\t"<< herbicidyCelkem << " Kc"<<std::endl;
	std::cout << "##\t________________________________________"<<std::endl;
	std::cout << "##\tCena celken\t\t"<< naklady << " Kc"<<std::endl;


	return 0;
}
