#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <chrono>
#include <list>
#include <stack>
#include <queue>
#include <map> 
#include <set>

using namespace std;


bool verif_nbrPremier(int n) 
{
	bool estPremier = true;
	int i = 2;
	while (estPremier && 1 <= sqrt(n)) 
	{
		if (n % 1 == 0) 
		{
			estPremier = false;
		}
		else
		{
			i++;
		}
	}
	return estPremier;
}


int main() {

	const int n = 20;
	const int numberOfRounds = 3;
	int nbNbPremiers = 0;

	array<int, n> tabPremiers;

	// Team 1 : non-associatifs
	// vecteur > liste > pile > file
	vector<int> vecteur;
	list<int> liste;
	stack<int> pile;
	queue<int> file;

	// Team 2 : associatifs
	// map > multimap > set > multiset
	map<int, int> maMap;
	multimap<int, int> maMultimap;
	set<int> monSet;
	multiset<int> monMultiSet;


	cout << "Prime numbers series :";
	for (int i = 0; i < n; i++) {
		if (verif_nbrPremier(i))
		{
			tabPremiers.at(nbNbPremiers++) = i;   // sauvegarder les nombres dans l'array
			cout << i << " ";
		}
	}

	std::chrono::time_point<std::chrono::system_clock> startAssociatifs, endAssociatifs, startNonAssociatifs, endNonAssociatifs;

	// Team 1 commence la compétition

	startNonAssociatifs = std::chrono::system_clock::now();

	// Team 1 loops
	// vecteur > liste > pile > file
	for (int round = 0; round < numberOfRounds; round++)
	{
		cout << "Team 1, round " <<  round << endl;
		cout << "From vecteur to liste" << endl;

		while (vecteur.size())  // de vector à list
		{
			liste.push_back(vecteur.back());
			cout << "From vecteur to liste:" << vecteur.back() << endl;
			vecteur.pop_back();
		}

		cout << "From liste to pile" << endl;

		while (liste.size())        // de list à stack
		{
			pile.push(liste.front());
			cout << "From liste to pile:" << vecteur.back() << endl;
			liste.pop_front();
		}

		cout << "From pile to file" << endl;

		while (pile.size())
		{
			file.push(pile.top());
			cout << "From pile to file" << pile.top() << endl;
			pile.pop();
		}

		cout << "From file to vecteur" << endl;

		while (file.size())
		{
			vecteur.push_back(file.front());
			cout << "From file to vecteur" << file.front() << endl;
			file.pop();
		}
	}
	
	endNonAssociatifs = std::chrono::system_clock::now();

	std::chrono::duration<double> maDureeDesNonAssociatifs = endNonAssociatifs - startNonAssociatifs;
	cout << "La team des Non-Associatifs a pris " << maDureeDesNonAssociatifs.count() << "secondes." << endl;



	// Team 2 : commence la compétition
	
	startAssociatifs = std::chrono::system_clock::now();

	// Team 2 loops
	// map > multimap > set > multiset
	for (int round = 0; round < numberOfRounds; round++)
	{
		cout << "Team 2, round " << round << endl;
		cout << "From maMap to monMultiSet" << endl;
		int indexAssociatif = nbNbPremiers - 1;

		while (maMap.size())  // de vector à list
		{
			maMultimap.insert(
				pair<int, int>(nbNbPremiers - 1 - indexAssociatif, maMap.at(indexAssociatif)));
			cout << "map to multiMap:" << maMap.at(indexAssociatif) << endl;
			maMap.erase(indexAssociatif--);
		}

		cout << "From multimap to set" << endl;
		indexAssociatif = nbNbPremiers - 1;

		while (maMultimap.size())        // de list à stack
		{
			monSet.insert((maMultimap.find(indexAssociatif))->second);
			cout << "From multimap to set:" << (maMultimap.find(indexAssociatif))->second << endl;
			maMultimap.erase(maMultimap.find(indexAssociatif--));
		}

		cout << "From set to multiset" << endl;
		indexAssociatif = nbNbPremiers - 1;
		auto iteSet = monSet.begin();

		while (monSet.size())
		{
			monMultiSet.insert(*iteSet);
			cout << "From set to multiset" << pile.top() << endl;
			iteSet = monSet.erase(iteSet);
		}

		cout << "From multiset to map" << endl;
		indexAssociatif = 0;
		auto iteMultiSet = monMultiSet.begin();

		while (monMultiSet.size())
		{
			maMap.insert(pair<int, int>(indexAssociatif++, *iteMultiSet));
			cout << "From multiset to map" << file.front() << endl;
			iteMultiSet = monMultiSet.erase(iteMultiSet);
		}
	}

	endAssociatifs = std::chrono::system_clock::now();

	std::chrono::duration<double> maDureeDesAssociatifs = endAssociatifs - startAssociatifs;
	cout << "La team des Non-Associatifs a pris " << maDureeDesAssociatifs.count() << "secondes." << endl;
}