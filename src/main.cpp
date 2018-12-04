#include <iostream>
#include <stdlib.h> 
#include <time.h>


#include "pripravaPudy.hpp"

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

	std::cout<<"##############################################"<<std::endl;


	// PODZMIMNI OSETROVANI

	return 0;
}
