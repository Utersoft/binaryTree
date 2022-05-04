#pragma once
#include "binaryTreeType.h"
#include <iostream>

using namespace std;


class researchTree {
private:
	knot* p_root;
	knot* p_currentKnot;
	int n_height;
	int n_leftSize;
	int n_rightSize;

public:
	researchTree();
	~researchTree();

	knot* getFirstKnot();

	void addKnot(int n_value);

	int heightOfTree(knot* root);
	int maxSize(int n_size1, int n_size2);
	int sizeOfTree(knot* root);
	void setToFirstRoot();
	knot* deleteKnot(int n_value, knot* root);

	void prefixRunThrough(knot* root);
	void infixeRunThough(knot* root);

	void balanceTree();

	void showKnot(knot* root);

	knot* biggestKnot(knot* root);

	knot* getParent(knot* root);

	void rotateLeft(knot* root);
	void rotateRight(knot* root);

	void deleteTree(knot* root);
};