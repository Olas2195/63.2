#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class dwie_jedynki {
	ifstream plik;
	
	public:
		dwie_jedynki();
		~dwie_jedynki();
		void wczytaj();
		bool sprawdzenie(string s);
};
dwie_jedynki::dwie_jedynki() {
	plik.open("ciagi.txt");
}
void dwie_jedynki::wczytaj() {
	string ciag;
	int ilosc=0;
	if(plik.good()) {
		while(!plik.eof()) {
			plik>>ciag;
			if(this->sprawdzenie(ciag)) {
				ilosc++;
			}
		}		
	}
	cout<<ilosc;
}
bool dwie_jedynki::sprawdzenie(string ciag) {
	for(int i=0; i<ciag.length(); i++) {
		if(ciag[i]=='1' && ciag[i+1]=='1') {
			return false;
		}
	}
	return true;
}
dwie_jedynki::~dwie_jedynki() {
	plik.close();
}

int main(int argc, char** argv) {
	dwie_jedynki c;
	c.wczytaj();
	return 0;
}
