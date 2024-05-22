#include <stdio.h>

int main()
{
  char *games[] = {"LoL",
                   "CS:GO",
                   "Albion Online",
                   "Civ 6",
                   "Lords Mobile",
                   "Clash of Clans"};

  char **steamGames[] = {&games[1],
                         &games[2],
                         &games[3]};

  char **mobileGames[] = {
      &games[4],
      &games[5]};

  printf("%s\n", *steamGames[1]);
  printf("%s\n", *mobileGames[0]);

  return 0;
}