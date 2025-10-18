#include <iostream>
#include <cmath>

struct Node
{
  Node *next;
  Node *previous;
  std::pair<int, int> value;
};

class DoublyLinkedList
{
public:
  Node *head;
  Node *tail;

  DoublyLinkedList()
  {
    Node *sentinelHeadNode = new Node();
    Node *sentinelTailNode = new Node();

    sentinelHeadNode->next = sentinelTailNode;
    sentinelHeadNode->previous = nullptr;

    sentinelTailNode->next = nullptr;
    sentinelTailNode->previous = sentinelHeadNode;

    this->head = sentinelHeadNode;
    this->tail = sentinelTailNode;
  }

  void push(Node *node)
  {
    if (this->tail->previous != nullptr)
    {
      this->tail->previous->next = node;
    }
    node->previous = this->tail->previous;
    this->tail->previous = node;
    node->next = this->tail;

    if (this->head->next == nullptr)
    {
      this->head->next = node;
    }
  }

  void swapAdjacentNodes(Node *i, Node *j)
  {
    Node *iPreviousTmp = i->previous;
    Node *jNextTmp = j->next;

    i->previous->next = j;
    i->next = j->next;
    i->previous = j;

    j->previous = iPreviousTmp;
    j->next = i;
    jNextTmp->previous = i;
  }

  void traverse()
  {
    Node *pivot = this->head->next;
    while (pivot->next != nullptr)
    {
      std::cout << "(" << pivot->value.first << "," << pivot->value.second << ")\n";
      pivot = pivot->next;
    }
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

  Node *pivot = head->next;
  while (pivot->next != nullptr && pivot->next->next != nullptr)
  {
    travelCost += calculateTraversalCost(pivot, pivot->next);
    pivot = pivot->next;
  }

  // last node to first node
  travelCost += calculateTraversalCost(pivot, head->next);

  return travelCost;
}

void optimizeRoute(DoublyLinkedList *list)
{
  Node *pivot = list->head->next;
  bool routeChangeInIteration = false;
  while (pivot->next != nullptr && pivot->next->next != nullptr)
  {
    double currentTraversalCost = calculateTraversalCost(pivot, pivot->next) + calculateTraversalCost(pivot->next, pivot->next->next);
    list->swapAdjacentNodes(pivot, pivot->next);
    double invertedTraversalCost = calculateTraversalCost(pivot->previous, pivot->previous->next) + calculateTraversalCost(pivot, pivot->next);

    if (currentTraversalCost <= invertedTraversalCost)
    {
      list->swapAdjacentNodes(pivot->previous, pivot);
    }
    else
    {
      routeChangeInIteration = true;
    }

    pivot = pivot->next;
  }

  if (routeChangeInIteration)
    optimizeRoute(list);
}

int main()
{
  DoublyLinkedList list;

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