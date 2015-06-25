#include "Game.hpp"
#include "GameStateManager.hpp"
#include "TitleState.hpp"
#include "AssetManager.hpp"

int main()
{
  AssetManager::Instance()->LoadContent();
  //Push the title screen
  GameStateManager::Instance()->Push(new TitleState);

  Game game;

  //Run the game
  game.Run();
}
