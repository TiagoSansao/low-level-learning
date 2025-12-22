#include <iostream>
#include <string>

using namespace std;

struct Node
{
  Node *left;
  Node *right;
  int value;
};

class Tree
{

public:
  Node *root;

  Tree()
  {
    this->root = nullptr;
  }

  void insert(Node *newNode)
  {
    if (this->root == nullptr)
    {
      this->root = newNode;
      return;
    }

    Node *pivot = this->root;
    Node *lastValidPivot = pivot;
    while (pivot != nullptr)
    {
      lastValidPivot = pivot;

      if (newNode->value > pivot->value)
      {
        pivot = pivot->right;

        if (pivot == nullptr)
          lastValidPivot->right = newNode;
      }
      else
      {
        pivot = pivot->left;
        if (pivot == nullptr)
          lastValidPivot->left = newNode;
      }
    }
  }
};

void preOrder(Node *root)
{
  cout << root->value << " ";
  if (root->left)
    preOrder(root->left);
  if (root->right)
    preOrder(root->right);
}

void posOrder(Node *root)
{
  if (root->left)
    posOrder(root->left);
  if (root->right)
    posOrder(root->right);
  cout << root->value << " ";
}

void inOrder(Node *root)
{
  if (root->left)
    inOrder(root->left);
  cout << root->value << " ";
  if (root->right)
    inOrder(root->right);
}

int main()
{
  Tree tree;

  unsigned int inputQuantity;
  cin >> inputQuantity;

  for (unsigned int i = 0; i < inputQuantity; i++)
  {
    int input;
    cin >> input;

    Node *newNode = new Node();
    newNode->value = input;
    newNode->left = nullptr;
    newNode->right = nullptr;

    tree.insert(newNode);
  }

  preOrder(tree.root);
  cout << '\n';
  inOrder(tree.root);
  cout << '\n';
  posOrder(tree.root);

  return 0;
}
