#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP

#include <stack>
#include "State.hpp"
#include <SFML/Graphics.hpp>

class GameStateManager
{
  public:
    static GameStateManager* Instance();

    void Init();

    void ProcessEvents(const sf::Event&);
    void Update(sf::Time);
    void Draw(sf::RenderWindow&);

    void Push(State*);
    void Pop();
    void ChangeState(State*);
    void Clear();
  private:
    std::stack<State*> mStateStack;

    //Singleton instance
    static GameStateManager* mpInstance;
  private:
    //Created so that the state machine can be a singleton
    GameStateManager(){}
    GameStateManager(GameStateManager const&){}
    GameStateManager& operator=(GameStateManager const&){return *this;}
};

#endif
