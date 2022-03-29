#include <stdio.h>
#include <stdlib.h>

// Structure Declaration Start
struct node
{
	char		key;
	struct node	*left;
	struct node	*right;
};
// Struct Declaration End

// Function prototypes Start
struct node	*getnode(char);
struct node	*insert_left(struct node *, char);
struct node	*insert_right(struct node *, char);
void	inorder(struct node *);
void	preorder(struct node *);
void	postorder(struct node *);
// Function prototypes End

// main function Start
int	main(void)
{
	struct node	*root = getnode('+');
	insert_left(root, 'A');
	insert_right(root, 'B');
	printf("\nIn-Order :-");
	inorder(root);
	printf("\nPre-Order :- ");
	preorder(root);
	printf("\nPort-Order :- ");
	postorder(root);
	puts("");
	return (0);
}

struct node	*getnode(char key)
{
	struct node	*temp = (struct node *)malloc(sizeof(struct node *));
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}

struct node	*insert_left(struct node *parent, char key)
{
	parent->left = getnode(key);
	return (parent->left);
}

struct node	*insert_right(struct node *parent, char key)
{
	parent->right = getnode(key);
	return (parent->right);
}

void	inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf(" %c ", root->key);
		inorder(root->right);
	}
}

void	preorder(struct node *root)
{
	if (root != NULL)
	{
		printf(" %c ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void	postorder(struct node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %c ", root->key);
	}
}



























