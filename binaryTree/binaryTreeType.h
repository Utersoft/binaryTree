#pragma once


typedef struct knot {
	int n_nb;
	knot* right_knot;
	knot* left_knot;
}knot;

typedef struct binarytree {
	knot* root;
}binaryTree;