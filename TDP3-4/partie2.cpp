#include <cmath>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void toutesLesPermutations(vector<string>& villes, int debut, int fin) {
    if (debut == fin) {
        for (const auto& ville : villes) {
            cout << ville << " ";
        }
        cout << endl;
    }
    else {
        // Permutations made
        for (int i = debut; i <= fin; i++) {
            // echange des deux lettres
            swap(villes[debut], villes[i]);
            // Appel Recursif
            toutesLesPermutations(villes, debut + 1, fin);
            // On revient à la situation précédente
            swap(villes[debut], villes[i]);
        }
    }
}

void toutesLesPermutations(vector<string>& villes, int debut, int fin);
int main() {
	vector<string> vecteurDeNomsDeVille{ "Lille", "Vda"};
	// string villes = "AB"; // AB | ABCD | ABDEF | ALGORITHME
	toutesLesPermutations(vecteurDeNomsDeVille, 0, vecteurDeNomsDeVille.size() - 1);
	return 0;
}