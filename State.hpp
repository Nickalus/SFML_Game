#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

enum StateType
{
  TITLE,
  MENU,
  PLAY,
  GAMEOVER
};

class State
{
  public:
    virtual ~State(){}

    virtual bool OnEnter() = 0;
    virtual bool OnExit() = 0;

    virtual void Update(sf::Time) = 0;
    virtual void Draw(sf::RenderWindow&) = 0;
    virtual void ProcessEvents(const sf::Event&) = 0;

    void SetType(StateType type){mStateType = type;}
    StateType GetType(){return mStateType;}
  protected:
    StateType mStateType;
};

#endif
