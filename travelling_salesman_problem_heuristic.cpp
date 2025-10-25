#include <iostream>
#include <cmath>

struct Node
{
  Node *next;
  Node *previous;
  std::pair<int, int> value;
};

class CircularLinkedList
{
public:
  Node *head;
  Node *tail;
  int size = 0;

  void push(Node *node)
  {
    if (this->size == 0)
    {
      this->head = node;
      this->tail = node;
    }

    this->tail->next = node;
    node->previous = this->tail;
    this->tail = node;
    node->next = this->head;
    this->head->previous = node;
    size++;
  }

  void swapAdjacentNodes(Node *i, Node *j)
  {
    std::swap(i->value, j->value);
  }

  void traverse()
  {
    std::cout << "----" << '\n';
    Node *pivot = this->head;
    do
    {
      std::cout << "(" << pivot->value.first << "," << pivot->value.second << ")\n";
      pivot = pivot->next;
    } while (pivot != this->head);
  }
};

double calculateTraversalCost(Node *fromNode, Node *toNode)
{
  double xi = fromNode->value.first;
  double yi = fromNode->value.second;

  double xj = toNode->value.first;
  double yj = toNode->value.second;

  return sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
}

double calculateTotalTravelCost(Node *head)
{
  double travelCost = 0.00;

  Node *pivot = head;
  do
  {
    travelCost += calculateTraversalCost(pivot, pivot->next);
    pivot = pivot->next;
  } while (pivot != head);

  return travelCost;
}

void optimizeRoute(CircularLinkedList *list)
{
  Node *pivot = list->head;
  bool routeChangeInIteration = false;
  do
  {
    double currentTraversalCost = calculateTraversalCost(pivot->previous, pivot) + calculateTraversalCost(pivot, pivot->next) + calculateTraversalCost(pivot->next, pivot->next->next);
    double invertedTraversalCost = calculateTraversalCost(pivot->previous, pivot->next) + calculateTraversalCost(pivot->next, pivot) + calculateTraversalCost(pivot, pivot->next->next);

    // std::cout << "Traverse before swap" << '\n';
    //  list->traverse();

    if (invertedTraversalCost < currentTraversalCost)
    {
      list->swapAdjacentNodes(pivot, pivot->next);
      // std::cout << "Traverse after swap" << '\n';
      // list->traverse();
      routeChangeInIteration = true;
    }
    else
    {
      pivot = pivot->next; // só mexer no pivot se n ter swap, pq se tiver, o pivot agora é o pivot->next
    }

  } while (pivot != list->head);

  if (routeChangeInIteration)
    optimizeRoute(list);
}

int main()
{
  CircularLinkedList list;

  int x, y;
  std::cin >> x >> y;
  while (x != -1)
  {
    Node *node = new Node();
    node->value = {x, y};
    list.push(node);

    std::cin >> x >> y;
  }

  double initialTravelCost = calculateTotalTravelCost(list.head);
  std::printf("%.2f\n", initialTravelCost);

  optimizeRoute(&list);

  double optimizedTravelCost = calculateTotalTravelCost(list.head);
  std::printf("%.2f\n", optimizedTravelCost);

  return 0;
}