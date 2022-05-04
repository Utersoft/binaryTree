#include "binaryTreeClass.h"



int main() {

	researchTree myTree;

	int n_choice = 0;
	int n_value = 0;

	do {
		system("cls");
		cout << "Que voulez-vous faire ?" << endl << "1. Ajouter un element a l'arbre." << endl << "2. Montrer les elements de l'arbre de gauche a droite" << endl << "3. Montrer les elements de l'arbre de bas en haut" << endl << "4. Effacer un element." << endl << "5. Equilibrer l'arbre." << endl << "0. Quittez." << endl;
		cin >> n_choice;
		cout << endl;

		system("cls");
		switch (n_choice) {
			case 1: {
				cout << "Indiquez la valeur que vous souhaitez ajouter." << endl << "Veuillez n'entrer que des entiers." << endl;
				cin >> n_value;
				myTree.addKnot(n_value);
				//myTree.balanceTree();
				system("cls");
				system("pause");
				break;
			}
			case 2: {
				if (myTree.getFirstKnot() == nullptr)
				{
					cout << "L'arbre est vide lol." << endl;
				}
				else {
					myTree.prefixRunThrough(myTree.getFirstKnot());
				}
				system("pause");
				break;
			}
			case 3: {
				if (myTree.getFirstKnot() == nullptr)
				{
					cout << "L'arbre est vide lol." << endl;
				}
				else {
					myTree.infixeRunThough(myTree.getFirstKnot());
					
				}
				system("pause");
				break;
			}
			case 4: {
				if (myTree.getFirstKnot() == nullptr) {
					cout << "L'arbre est vide, impossible d'effacer des donnees lol." << endl;
				}
				else {
					cout << "Quelle valeur souhaitez-vous effacer?" << endl;
					cin >> n_value;
					myTree.deleteKnot(n_value, myTree.getFirstKnot());
				}
				system("pause");
				break;
			}
			case 5: {
				myTree.balanceTree();
			}
			default:
				n_choice = 0;
				break;
		}
	} while (n_choice != 0);

	return 0;
}