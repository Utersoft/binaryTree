#include "binaryTreeClass.h"

//Constructeur
researchTree::researchTree()
{
	p_root = nullptr;
	p_currentKnot = p_root;
	n_height = 0;
	n_leftSize = 0;
	n_rightSize = 0;
}

//Destructeur
researchTree::~researchTree()
{
	deleteTree(p_root);
}

//retourne la racine
knot* researchTree::getFirstKnot()
{
	return p_root;
}


//Ajout d'un noeud
void researchTree::addKnot(int n_value)
{
	knot* newKnot = new knot;
	knot* p_previousKnot = nullptr;

	//initialisation du noeud
	newKnot->n_nb = n_value;
	newKnot->left_knot = nullptr;
	newKnot->right_knot = nullptr;


	//On vérifie que l'arbre contient déjà une valeur et sinon on y ajoute une
	if (p_root == nullptr) {
		p_root = newKnot;
		this->setToFirstRoot();
	}
	else { //Sinon on cherche un emplacement libre en vérifiant si la valeur du noeud suivant est plus grand ou plus petit que le nouveau
		this->setToFirstRoot();
		while (p_currentKnot) {
			p_previousKnot = p_currentKnot;

			if (newKnot->n_nb < p_currentKnot->n_nb) {
				p_currentKnot = p_currentKnot->left_knot;
			}
			else {
				p_currentKnot = p_currentKnot->right_knot;
			}
		}

		if (p_previousKnot) {
			if (newKnot->n_nb < p_previousKnot->n_nb) {
				p_previousKnot->left_knot = newKnot;
			}
			else {
				p_previousKnot->right_knot = newKnot;
			}
		}
	}
}

//Calcul de la hauteur de l'arbre
int researchTree::heightOfTree(knot* root)
{
	int n_leftHeight = 0;
	int n_rightHeight = 0;
	if (root == nullptr) {
		return 0;
	}
	n_leftHeight = heightOfTree(root->left_knot);
	n_rightHeight = heightOfTree(root->right_knot);
	return maxSize(n_leftHeight, n_rightHeight) + 1;
}

//Détermine la valeur max entre 2 taille données
int researchTree::maxSize(int n_size1, int n_size2)
{
	if (n_size1 >= n_size2) {
		return n_size1;
	}
	else {
		return n_size2;
	}
}
//Calcul du nombre de noeud qu'il y a
int researchTree::sizeOfTree(knot* root)
{
	if (root == nullptr) {
		return 0;
	}
	n_leftSize = sizeOfTree(root->left_knot);
	n_rightSize = sizeOfTree(root->right_knot);
	return n_leftSize + n_rightSize + 1;
}

//Positionne le noeud courant à la racine
void researchTree::setToFirstRoot()
{
	if (p_root != nullptr) {
		p_currentKnot = p_root;
	}
}

//Suppression d'un noeud
knot* researchTree::deleteKnot(int n_value, knot* root)
{
	if (p_root != nullptr) {
		if (root->n_nb > n_value) {
			root->left_knot = deleteKnot(n_value, root->left_knot);
		}
		else if (root->n_nb < n_value) {
			root->right_knot = deleteKnot(n_value, root->right_knot);
		}
		else {
			if (root->left_knot == nullptr) {
				return root->right_knot;
			}
			else if (root->right_knot == nullptr) {
				return root->left_knot;
			}
			else {
				knot* tempKnot = biggestKnot(root->right_knot);
				if (root != nullptr) {
					root->n_nb = tempKnot->n_nb;
					deleteKnot(tempKnot->n_nb, root->right_knot);
				}
			}
		}
	}
	return root;
}


//Lecture de haut en bas
void researchTree::prefixRunThrough(knot* root)
{
	if (root != nullptr) {
		showKnot(root);
		prefixRunThrough(root->left_knot);
		prefixRunThrough(root->right_knot);
	}
}

//Lecture de gauche à droite
void researchTree::infixeRunThough(knot* root)
{
	if (root != nullptr) {
		prefixRunThrough(root->left_knot);
		showKnot(root);
		prefixRunThrough(root->right_knot);
	}
}

//Equilibrage de l'arbre
void researchTree::balanceTree()
{
	//Vérification que l'arbre n'est pas null
	if (p_root == nullptr) {
		return;
	}

	//Comparaison de la taille des deux branches de la racine pour déterminer s'il faut une rotation droite ou gauche
	int n_balanceRoot = heightOfTree(p_root->right_knot) - heightOfTree(p_root->left_knot);
	if (n_balanceRoot == 2) {
		int n_balanceRightRoot = heightOfTree(p_root->right_knot->right_knot) - heightOfTree(p_root->right_knot->left_knot);
		if (n_balanceRightRoot == -1) {
			rotateRight(p_root->right_knot);
		}
		rotateLeft(p_root);
	}
	else if (n_balanceRoot == -2) {
		int n_balanceLeftRoot = heightOfTree(p_root->left_knot->right_knot) - heightOfTree(p_root->left_knot->left_knot);
		if (n_balanceLeftRoot == 1) {
			rotateLeft(p_root->left_knot);
		}
		rotateRight(p_root);
	}

}

//Affichage d'un noeud
void researchTree::showKnot(knot* root)
{
	if (root != nullptr) {
		cout << "Valeur du noeud : " << root->n_nb << endl << endl;
	}
}

//Récupération du noeud le plus grand parmi deux noeuds
knot* researchTree::biggestKnot(knot* root)
{
	if (root->right_knot == nullptr) {
		return root;
	}

	return biggestKnot(root->right_knot);
}


//Récupération du parent d'un noeud
knot* researchTree::getParent(knot* root)
{
	if (p_root == nullptr) {
		return nullptr;
	}

	if (p_currentKnot == nullptr) {
		setToFirstRoot();
	}

	//this->setToFirstRoot();

	/*bool isFather = false;

	do {
		if (p_currentKnot != nullptr) {
			if (p_currentKnot->left_knot != nullptr) {
				if (p_currentKnot->left_knot->n_nb == root->n_nb) {
					return p_currentKnot;
				}
			}else if (p_currentKnot->right_knot != nullptr) {
				if (p_currentKnot->right_knot->n_nb == root->n_nb) {
					return p_currentKnot;
				}
			}
			else {
				if (p_currentKnot->n_nb < root->n_nb) {
					p_currentKnot = p_currentKnot->left_knot;
				}
				else if (p_currentKnot->n_nb > root->n_nb) {
					p_currentKnot = p_currentKnot->right_knot;
				}
			}
		}
		else {
			isFather = true;
		}
	} while (!isFather);*/
	
	if (p_currentKnot->left_knot == root || p_currentKnot->right_knot == root) {
		return p_currentKnot;
	}
	else {
		if (p_currentKnot->n_nb < root->n_nb) {
			p_currentKnot = p_currentKnot->right_knot;
			return getParent(root);
		}
		else {
			p_currentKnot = p_currentKnot->left_knot;
			return getParent(root);
		}
	}

	//return p_currentKnot;
}

//Rotation vers la gauche d'un noeud
void researchTree::rotateLeft(knot* root)
{
	if (p_root == nullptr) {
		return;
	}

	knot* rightKnot = root->right_knot;
	knot* parent = getParent(root);

	if (parent != nullptr) {
		if (parent->right_knot == root) {
			parent->right_knot = rightKnot;
		}
		else {
			parent->left_knot = rightKnot;
		}
	}
	
	root->right_knot = rightKnot->left_knot;

	rightKnot->left_knot = root;
	if (root == p_root) {
		p_root = rightKnot;
	}

}

//Rotation vers la droite d'un noeud
void researchTree::rotateRight(knot* root)
{
	//On vérifie si l'arbre existe
	if (p_root == nullptr) {
		return;
	}

	knot* leftKnot = root->left_knot;
	knot* parent = getParent(root);

	//On récupère le parent pour lui assigner le nouvel enfant
	if (parent != nullptr) {
		if (parent->left_knot == root) {
			parent->left_knot = leftKnot;
		}
		else {
			parent->right_knot = leftKnot;
		}
	}

	root->left_knot = leftKnot->right_knot;

	leftKnot->right_knot = root;
	if (root == p_root) {
		p_root = leftKnot;
	}
}

//destruction de l'arbre
void researchTree::deleteTree(knot* root)
{
	if (root != nullptr) {
		deleteTree(root->left_knot);
		deleteTree(root->right_knot);
		delete(root);
	}
}

