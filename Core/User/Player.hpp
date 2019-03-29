#pragma once
#include "Gui.hpp"

class Player : public std::enable_shared_from_this<Player> {
public:
  Player();
  ~Player();

  std::shared_ptr<Gui> gui;

private:

};
