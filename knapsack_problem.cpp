#include <iostream>
#include <vector>

struct Item
{
  float mean;
  int quantity;
  int weight;
  int itemType;
};

void sortArray(std::vector<Item> &itemVector)
{
  for (int i = 0; i < itemVector.size(); i += 1)
  {
    for (int j = 0; j < itemVector.size() - 1; j += 1)
    {
      if (itemVector[j].mean < itemVector[j + 1].mean)
      {
        Item swap = itemVector[j];
        itemVector[j] = itemVector[j + 1];
        itemVector[j + 1] = swap;
      }
    }
  }
};

int main()
{
  std::vector<Item> itemVector = {};

  int u, w, d;
  int itemType = 0;
  while (u != -1)
  {
    std::cin >> u >> w >> d;

    float mean = static_cast<double>(u) / static_cast<double>(w);
    Item item = {mean, d, w, itemType};
    itemVector.push_back(item);
    itemType++;
  }

  sortArray(itemVector);

  int cap;
  std::cin >> cap;
  int capUsed = 0;

  for (int i = 0; cap > capUsed; i += 1)
  {
    if (i >= itemVector.size() - 1)
      return 0;

    int ksnapsackItemQuantity = 0;
    while (capUsed + ((ksnapsackItemQuantity + 1) * itemVector[i].weight) <= cap && ksnapsackItemQuantity < itemVector[i].quantity)
    {
      ksnapsackItemQuantity++;
    }

    if (ksnapsackItemQuantity == 0)
      continue;

    std::cout << itemVector[i].itemType << ' ' << ksnapsackItemQuantity << '\n';
    capUsed += ksnapsackItemQuantity * itemVector[i].weight;
  }
}
