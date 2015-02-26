#include "Game.hpp"
#include "GameStateManager.hpp"
#include "TitleState.hpp"

int main()
{
  //Push the title screen
  GameStateManager::Instance()->Push(new TitleState);

  Game game;

  //Run the game
  game.Run();
}
