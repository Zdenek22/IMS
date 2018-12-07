#include <iostream>
#include <stdlib.h> 
#include <time.h>


#include "pripravaPudy.hpp"
#include "jaro.hpp"
#include "podzim.h"

int main(int argc, char** argv){
	
	srand(time(NULL));
	float naklady = 0.0;
	float tmp = 0.0;
	float tmpNafta = 0.0;
	float pole = std::stof(argv[1]);
	int technologie = std::atoi(argv[2]);
	float hnojivoCelkem = 0.0;
	float postrikyCelkem = 0.0;
	float regulatoryCelkem = 0.0;
	float herbicidyCelkem = 0.0;
	float pripravaCelkem = 0.0;
	float naftaCelkem = 0.0;
	float tech = 0.0;
	

	pripravaPudy priprava;
	
	std::cout<<"\n\n############### PRIPRAVA PUDY #############################"<<std::endl << "##" << std::endl << "##" << std::endl;

	tmp = naklady;
	tmpNafta = naftaCelkem;
	priprava.uklid(&naklady, pole, &naftaCelkem);
	std::cout << "##\tUklid slamy\t\t\t\tcelkove naklady" <<std::endl;
	std::cout << "##\t"<<(naklady -tmp)<< " Kc\t\t\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	tech = naklady;

	tmp = naklady;
	tmpNafta = naftaCelkem;
	priprava.aplikaceHnojiv(&naklady, pole, &naftaCelkem);
	std::cout << "##\tAplikace hnojiv"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<<naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;

	// vyber technologie, 1 - klasicka, 2 - minimalizacni, 3 - bezorebna
	if(technologie == 1){
		priprava.klasickaPriprava(&naklady, pole, &naftaCelkem);
		std::cout << "##\tKlasicke pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
		tech = tech + (naklady - tmp);

	}
	else if(technologie == 2){
		priprava.minimalizacniPriprava(&naklady, pole, &naftaCelkem);
		std::cout << "##\tMinimalizacni pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
		tech = tech + (naklady - tmp);
	}
	else{
		std::cout << "##\tBezorebne pripraveni pudy"<<std::endl;
		std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
		tech = tech + (naklady - tmp);
	}

	tmp = naklady;
	tmpNafta = naftaCelkem;
	priprava.seti(&naklady, pole, &naftaCelkem);
	std::cout << "##\tVysazeni semen repky"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	float seti = (naklady - tmp)- (naftaCelkem - tmpNafta);

	std::cout<<"################### PODZIM #####################\n##"<<std::endl;

	// PODZMIMNI OSETROVANI
	tmp = naklady;
	tmpNafta = naftaCelkem;
	aplikaceHerbicidu(&naklady, pole, &naftaCelkem);
	std::cout << "##\tAplikace herbicidu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	herbicidyCelkem = herbicidyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);	


	tmp = naklady;
	tmpNafta = naftaCelkem;
	krytonosecSesulovy(&naklady, pole, &naftaCelkem);
	std::cout << "##\tPostrik proti krytonosci sesulovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	drepcik(&naklady, pole, &naftaCelkem);
	std::cout << "##\tPostrik proti drepcikovi"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);	

	tmp = naklady;
	tmpNafta = naftaCelkem;
	hrabosi(&naklady, pole, &naftaCelkem);
	std::cout << "##\tPostrik proti hrabosum"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);	

	tmp = naklady;
	tmpNafta = naftaCelkem;
	regRustu(&naklady, pole, &naftaCelkem);
	std::cout << "##\tAplikace regulatoru vzrustu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	regulatoryCelkem = regulatoryCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	pilatka(&naklady, pole, &naftaCelkem);
	std::cout << "##\tPostrik proti pilatkam"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);


	std::cout<<"################### JARO #######################\n##"<<std::endl;

	// JARNI OSETROVANI
	jaro jarniOsetreni;

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.regenHnojeni(&naklady, pole, &naftaCelkem);
	std::cout << "##\tRegeneracni hnojeni"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);	

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.produkHnojeni(&naklady, pole, &naftaCelkem);
	std::cout << "##\tProdukcni hnojeni"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.krytonosecRepkovy(&naklady, pole, &naftaCelkem);
	std::cout << "##\tOchrana proti krytonosci repkovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);	

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.regulatorRustu(&naklady, pole, &naftaCelkem);
	std::cout << "##\tAplikace regulatoru rustu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	regulatoryCelkem = regulatoryCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.blyskacek(&naklady, pole, &naftaCelkem);
	std::cout << "##\tOchrana proti blyskackovi"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.listovaHnojiva(&naklady, pole, &naftaCelkem);
	std::cout << "##\tAplikace listovych hnojiv"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.doladovaciDusik(&naklady, pole, &naftaCelkem);
	std::cout << "##\tDoladovaci davka dusiku"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	hnojivoCelkem = hnojivoCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.bejlomorka(&naklady, pole, &naftaCelkem);
	std::cout << "##\tOchrana proti bejlomorce"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);	

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.krytonosecSesulovy(&naklady, pole, &naftaCelkem);
	std::cout << "##\tOchrana proti krytonosci sesulovemu"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.msice(&naklady, pole, &naftaCelkem);
	std::cout << "##\tOchrana proti msicim"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc (Z toho nafty: "<< naftaCelkem - tmpNafta<<" Kc)\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	
	postrikyCelkem = postrikyCelkem + (naklady - tmp)- (naftaCelkem - tmpNafta);

	tmp = naklady;
	tmpNafta = naftaCelkem;
	jarniOsetreni.sklizen(&naklady, pole, &naftaCelkem);
	std::cout << "##\tSklizen"<<std::endl;
	std::cout << "##\t"<<(naklady -tmp) << " Kc\t\t\t\t"<< naklady<< " Kc"<<std::endl<<"##"<<std::endl;	

	
	std::cout<<"############## CELKOVE HODNOTY #################\n##"<<std::endl;
	std::cout << "##\tOsivo\t\t\t"<< seti << " Kc"<<std::endl;
	std::cout << "##\tHnojivo\t\t\t"<< hnojivoCelkem << " Kc"<<std::endl;
	std::cout << "##\tOchrana proti skudcum\t"<< postrikyCelkem << " Kc"<<std::endl;
	std::cout << "##\tRegulatory\t\t"<< regulatoryCelkem << " Kc"<<std::endl;
	std::cout << "##\tHerbicidy\t\t"<< herbicidyCelkem << " Kc"<<std::endl;
	std::cout << "##\tNafta\t\t\t"<< naftaCelkem << " Kc"<<std::endl;
	std::cout << "##\t________________________________________"<<std::endl;
	std::cout << "##\tCena celkem\t\t"<< naklady << " Kc"<<std::endl;
	std::cout << "##\tTechnologie\t\t"<< tech << " Kc"<<std::endl;
	std::cout<<"##\n################################################"<<std::endl;


	return 0;
}
