#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INFINI = 9999999;

// Définition de la matrice d'adjacence
int nbr_sommets = 7; // Nombre de sommets
vector<vector<int>> grapheEtCapacites(nbr_sommets, vector<int>(nbr_sommets, 0)); // vecteur de vecteur pour la matrice


bool parcoursLargeur(vector<vector<int>> graphe, int s, int t, vector<int> &predDansCheminAmeliorant) {  // s = sommet départ ; t = sommet arrivée
	
	int nbSommets = graphe.size();
	vector<bool> sommetVisite(nbSommets, false);   // on initialise les sommets comme étant tous non visités

	// Structure du chemin en largeur
	queue<int> file;

	// Initialisation
	file.push(s);
	sommetVisite[s] = true;             // le sommet s a été visité
	predDansCheminAmeliorant[s] = 0;   // le sommet de départ n'a pas d'antécédent
	

	while (!file.empty())
	{
		int u = file.front();
		file.pop();

		for (int v = 0; v < nbSommets; v++)
		{
			if (!sommetVisite[v] && graphe[u][v] > 0)  // si sommet non visité et arc existant
			{
				file.push(v);
				predDansCheminAmeliorant[v] = u; 
				sommetVisite[v] = true;

				if (v == t) {
					return true; // Chemin trouvé jusqu'au sommet d'arrivée t
				}
			}
		}
	}
	return false;
}
 
int fordFulkeson(vector<vector<int>> graphe, int s, int t) {   // s et t les indices des deux noeuds
	int u, v;
	
	int nbSommets = graphe.size();
	vector<vector<int>> grapheResiduel = graphe;
	
	vector<int> predDansCheminAmeliorant(nbSommets, 0);

	int max_flow = 0;  // flox max courant

	while (parcoursLargeur(grapheResiduel, s, t, predDansCheminAmeliorant))
	{
		int ameliorationFlot = INFINI;
		for (int v = t; v != s; v = predDansCheminAmeliorant[v])
		{
			u = predDansCheminAmeliorant[v];
			ameliorationFlot = min(ameliorationFlot, grapheResiduel[u][v]);
		}
		for (int v = t; v != s; v = predDansCheminAmeliorant[v])
		{
			u = predDansCheminAmeliorant[v];
			grapheResiduel[u][v] -= ameliorationFlot;
			grapheResiduel[v][u] += ameliorationFlot;
		}
		max_flow += ameliorationFlot;
	}
	return max_flow;
}




int main() {

	// Mettre toutes les capacités des arcs à INFINI
	for (int i = 0; i < nbr_sommets; i++)
	{
		for (int j = 0; j < nbr_sommets; j++)
		{
			grapheEtCapacites[i][j] = 0;
		}
	}

	// Ajout des capacités entre les villes :
	grapheEtCapacites[0][1] = 50; // Stuttgart -> Rotterdam
	grapheEtCapacites[0][2] = 70; // Stuttgart -> Bordeaux
	grapheEtCapacites[0][3] = 40; // Stuttgart -> Lisbone
	grapheEtCapacites[1][4] = 60; // Rotterdam -> New York
	grapheEtCapacites[4][6] = 80; // New York -> Los Angeles
	grapheEtCapacites[2][4] = 40; // Bordeaux -> New York
	grapheEtCapacites[2][5] = 50; // Bordeaux -> New Orleans
	grapheEtCapacites[3][5] = 30; // Lisbone -> New Orleans
	grapheEtCapacites[5][6] = 70; // New Orleans -> Los Angeles


	// Affichage de la matrice d’adjacence
	cout << "Matrice d'adjacence de capacite :\n";
	for (int i = 0; i < nbr_sommets; i++) {
		for (int j = 0; j < nbr_sommets; j++) {
			if (grapheEtCapacites[i][j] == 0)
				cout << "0  ";
			else
				cout << grapheEtCapacites[i][j]<< "  ";
		}
		cout << endl;
	}

	int flow = fordFulkeson(grapheEtCapacites, 0, 6);
	cout << "Le flot maximal est : " << flow << endl;

	return 0;

}