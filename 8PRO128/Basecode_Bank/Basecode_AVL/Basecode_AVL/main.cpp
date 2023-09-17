#include "Settings.h"
#include "AVL.h"

int main(void)
{
	srand(time(nullptr));

	AVLTree<int>* tree = new AVLTree<int>;

	for (int i = 0; i < 1000; i++)
	{
		int* value = new int(rand() % 1000);
		tree->Insert(value);
	}

	tree->PrintList();
	tree->PrintTree();

	delete tree;

	return EXIT_SUCCESS;
}
