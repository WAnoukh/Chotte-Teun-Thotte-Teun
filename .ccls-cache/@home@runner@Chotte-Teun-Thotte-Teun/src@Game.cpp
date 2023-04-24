#include "../head/Game.h"

Game *Game::instance = nullptr;

Game &Game::getInstance() {
  if (instance == nullptr) {
    instance = new Game();
  }
  return *instance;
}

void Game::freeInstance() {
  delete instance;
  instance = nullptr;
}

Game::Game() {
  size_t i = 0;
  for (auto c : Colors) {
    for (auto n : Numbers) {
      clanCards[i] = new Clan(c, n);
      i++;
    }
  }
  const string chef1 = "Chief1";
  tacticalCards[0] = new Elite("Chief1");
  tacticalCards[1] = new Elite("Chief2");
  tacticalCards[2] = new Elite("Spy");
  tacticalCards[3] = new Elite("Shield-Bearer");
  tacticalCards[4] = new CombatMode("Blind-Man’s Bluff");
  tacticalCards[5] = new CombatMode("Mud Fight");
  tacticalCards[6] = new Ruses("Recruiter");
  tacticalCards[7] = new Ruses("Strategist");
  tacticalCards[8] = new Ruses("Banshee");
  tacticalCards[9] = new Ruses("Traiter");
}