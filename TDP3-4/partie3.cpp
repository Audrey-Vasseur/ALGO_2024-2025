#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>

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
	int nbLettresNomVille = tailleMinNomVille + rand() % (tailleMaxNomVille - tailleMinNomVille + 1);
	for (int i = 0; i < nbLettresNomVille; i++)
	{
		for (int i = 0; i < nbLettresNomVille; i++)
		{
			cout << "" << endl;
		}
	}
}