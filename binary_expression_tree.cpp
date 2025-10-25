#include <iostream>
#include <string>

using namespace std;

struct Node
{
  Node *left;
  Node *right;
  string value;
};

int findLowestPredecenceOperatorIndex(const string &infixExpression)
{
  for (int i = infixExpression.size() - 1; i >= 0; i--)
  {
    if (infixExpression[i] == '+' || infixExpression[i] == '-')
    {
      return i;
    }
  }

  for (int i = infixExpression.size() - 1; i >= 0; i--)
  {
    if (infixExpression[i] == '/' || infixExpression[i] == '*')
    {
      return i;
    }
  }

  return NULL;
}

Node *buildTree(Node *root)
{
  int lowestPredecenceOperatorIndex = findLowestPredecenceOperatorIndex(root->value);
  if (lowestPredecenceOperatorIndex == NULL)
    return nullptr;

  Node *leftNode = new Node;
  leftNode->value = root->value.substr(0, lowestPredecenceOperatorIndex);
  root->left = leftNode;
  buildTree(leftNode);

  Node *rightNode = new Node;
  rightNode->value = root->value.substr(lowestPredecenceOperatorIndex + 1);
  root->right = rightNode;
  buildTree(rightNode);

  root->value = root->value[lowestPredecenceOperatorIndex];

  return root;
}

void preOrder(Node *root)
{
  cout << root->value;
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
  cout << root->value;
}

int main()
{
  string infixExpression;

  cin >> infixExpression;

  Node *root = new Node();
  root->value = infixExpression;
  buildTree(root);

  preOrder(root);
  cout << '\n';
  posOrder(root);
  cout << '\n';

  return 0;
}
