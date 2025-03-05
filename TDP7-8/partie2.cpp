#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INFINI = 9999999;

// Définition de la matrice d'adjacence
int nbr_sommets = 7; // Nombre de sommets
vector<vector<int>> capacity(nbr_sommets, vector<int>(nbr_sommets, INFINI)); // vecteur de vecteur pour la matrice

int main() {

	// Mettre toutes les capacités des arcs à INFINI
	for (int i = 0; i < nbr_sommets; i++)
	{
		for (int j = 0; j < nbr_sommets; j++)
		{
			capacity[i][j] = INFINI;
		}
	}

	// Ajout des capacités entre les villes :
	capacity[0][1] = 50; // Stuttgart -> Rotterdam
	capacity[0][2] = 70; // Stuttgart -> Bordeaux
	capacity[0][3] = 40; // Stuttgart -> Lisbone
	capacity[1][4] = 60; // Rotterdam -> New York
	capacity[4][6] = 80; // New York -> Los Angeles
	capacity[2][4] = 40; // Bordeaux -> New York
	capacity[2][5] = 50; // Bordeaux -> New Orleans
	capacity[3][5] = 30; // Lisbone -> New Orleans
	capacity[5][6] = 70; // New Orleans -> Los Angeles


	// Affichage de la matrice d’adjacence
	cout << "Matrice d'adjacence de capacite :\n";
	for (int i = 0; i < nbr_sommets; i++) {
		for (int j = 0; j < nbr_sommets; j++) {
			if (capacity[i][j] == INFINI)
				cout << "INF ";
			else
				cout << capacity[i][j]<< "  ";
		}
		cout << endl;
	}

}