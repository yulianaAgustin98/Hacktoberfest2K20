
#include <bits/stdc++.h> 
using namespace std; 


struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

void Swap(Node **a, Node **b) 
{ 
	Node * temp = *a; 
	*a = *b; 
	*b = temp; 
} 

Node **firstPtr; 
Node **secondPtr; 


void pairwiseSwap(Node **root, int &count) 
{ 
	if (!(*root)) 
		return; 

	if(!(*root)->left&&!(*root)->right) 
	{ 
		secondPtr = root; 

		 
		count++; 
		if (count%2 == 0) 
			Swap(firstPtr, secondPtr); 

		else

			
			firstPtr = secondPtr; 
	} 

 
	if ((*root)->left) 
		pairwiseSwap(&(*root)->left, count); 
 
	if ((*root)->right) 
		pairwiseSwap(&(*root)->right, count); 

} 


Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

 
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 

	printInorder(node->left); 

	printf("%d ", node->data); 

	
	printInorder(node->right); 
} 


int main() 
{ 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->right->left = newNode(5); 
	root->right->right = newNode(8); 
	root->right->left->left = newNode(6); 
	root->right->left->right = newNode(7); 
	root->right->right->left = newNode(9); 
	root->right->right->right = newNode(10); 

	cout << "Inorder traversal before swap:\n"; 
	printInorder(root); 
	cout << "\n"; 

	int c = 0; 
 
	pairwiseSwap(&root, c); 

	
	cout << "Inorder traversal after swap:\n"; 
	printInorder(root); 
	cout << "\n"; 

	return 0; 
} 
