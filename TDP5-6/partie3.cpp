#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Déclaration des variables :
const int TAILLEDUGRAPHE = 6;
const int INFINI = 9999999;
vector<string>vecSommets;			// vecteur qui peut prendre le nom d’une ville (string)
int arcs[TAILLEDUGRAPHE][TAILLEDUGRAPHE];		// tableau 2 dimensions contenant la distance entre deux sommets/villes
												 
int cheminCourt[TAILLEDUGRAPHE][TAILLEDUGRAPHE];   // sauvegarde la distance totale du Plus Court Chemin pour chaque couple de sommets. 
												   // valeurs de départ = valeurs de arcs
											       // (matrice de la même taille que arcs)

int pointChemin[TAILLEDUGRAPHE][TAILLEDUGRAPHE];   // sauvegarde les noeuds intermédiaires par lesquels le chemin passe
												   // (et matrice même taille que vecSommets)

// --> tailleGraphe correspond au nombre de sommets/villes.

// Le tableau 2D arc fait penser à une matrice

int main(){

// Ajout des sommets des villes :
vecSommets.push_back("Lille");
vecSommets.push_back("Lens");
vecSommets.push_back("Paris");
vecSommets.push_back("Bourges");
vecSommets.push_back("Clermont Ferrand");
vecSommets.push_back("Montpellier");

// Affichage des noms des villes
for (int i = 0; i < vecSommets.size(); i++)
{
	cout << "Nom de la ville : " << vecSommets[i] << endl;
}


// Mettre toutes les distances des arcs à INFINI 
for (int i = 0; i < TAILLEDUGRAPHE; i++)
{
	for (int j = 0; j < TAILLEDUGRAPHE; j++)
	{
		arcs[i][j] = INFINI;
	}
}

// On remplace par de vraies distances
arcs[0][1] = 40;  // Lille -> Lens
arcs[0][2] = 230;  // Lille -> Paris
arcs[2][3] = 250;  // Paris -> Bourges
arcs[2][4] = 425;  // Paris -> Clermont Ferrand
arcs[3][4] = 190;  // Bourges -> Clermont Ferrand
arcs[4][5] = 300;  // Clermont Ferrand -> Montpellier

// Affichage des distances
cout << "\nDistance entre " << vecSommets[0] <<" et " << vecSommets[1] <<": " << arcs[0][1] << endl;
cout << "Distance entre " << vecSommets[0] << " et " << vecSommets[2] << ": " << arcs[0][2] << endl;
cout << "Distance entre " << vecSommets[2] << " et " << vecSommets[3] << ": " << arcs[2][3] << endl;
cout << "Distance entre " << vecSommets[2] << " et " << vecSommets[4] << ": " << arcs[2][4] << endl;
cout << "Distance entre " << vecSommets[3] << " et " << vecSommets[4] << ": " << arcs[3][4] << endl;
cout << "Distance entre " << vecSommets[4] << " et " << vecSommets[5] << ": " << arcs[4][5] << endl;

// Initialisation de pointChemin
for (int i = 0; i < vecSommets.size(); i++)
{
	for (int j = 0; j < vecSommets.size(); j++)
	{
		if (arcs[i][j] == INFINI)
		{
			pointChemin[i][j] = -1;
		}
		else
		{
			pointChemin[i][j] = i;
		}
	}
}

// Implémentation de l'algorithme de Floyd-Warshall
for (int i = 0; i < TAILLEDUGRAPHE; i++)
{
	for (int i = 0; i < TAILLEDUGRAPHE; i++)
	{
		for (int i = 0; i < TAILLEDUGRAPHE; i++)
		{
			if (cheminCourt[0][] + cheminCourt[][] < cheminCourt[][])
			{

			}
		}
	}
}



}