#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
# include <tuple>  // make_tuple
#include <utility>  // pair
#include <map>
#include <cmath>

using namespace std;

constexpr int codeASCIIde_a = 97;
constexpr int codeASCIIde_A = 65;
constexpr int nombreDeLettres = 26;
constexpr int tailleMinNomVille = 4;
constexpr int tailleMaxNomVille = 12;
constexpr int grainePourLeRand = 1;
constexpr int nombreDeVilles = 4;
constexpr int nombreCombinaisons = 24;
constexpr int tailleCoteCarte = 100;

vector<string> vecteurDeNomsDeVille{ "Lille", "Vda" };


int main() {

	std::map<std::string, std::tuple<int, int, int>> maMapNomsVillesEtCoordonnees;
	for (auto i = 0; i < nombreDeVilles; i++)
	{
		std::string monStringTemp;
		int ASCIItempLettre;
		int nbLettresNomVille = tailleMinNomVille + rand() % (tailleMaxNomVille - tailleMinNomVille - 1);

		ASCIItempLettre = codeASCIIde_A + rand() % (nombreDeLettres);
		monStringTemp.push_back(char(ASCIItempLettre));
		for (auto j = 1; j < nbLettresNomVille; j++)
		{
			ASCIItempLettre = codeASCIIde_a + rand() % (nombreDeLettres);
			monStringTemp.push_back(char(ASCIItempLettre));
		}
		int tempX, tempY;
		tempX = rand() % (tailleCoteCarte + 1);
		tempY = rand() % (tailleCoteCarte + 1);

		//  ajouter chaque ville
		auto tempTuple_indexVille_X_Y = std::make_tuple(i, tempX, tempY);
		maMapNomsVillesEtCoordonnees.insert(maMapNomsVillesEtCoordonnees.begin(), std::pair<std::string, std::tuple<int, int, int>>(monStringTemp, tempTuple_indexVille_X_Y));
		vecteurDeNomsDeVille.push_back(monStringTemp);
	}

	// affichage du nom+tuple de chaque ville
	for (auto it = maMapNomsVillesEtCoordonnees.begin(); it != maMapNomsVillesEtCoordonnees.end(); ++it)
	{
		std::cout << it->first << " " << std::get<0>(it->second) << " " << std::get<1>(it->second) << " " << std::get<2>(it->second) << std::endl;
	}

	// récupérer l'indice de la ville
	//int indiceVilleDepart = get<0>((maMapNomsVillesEtCoordonnees.find(*itVecVilles))->second);
}

