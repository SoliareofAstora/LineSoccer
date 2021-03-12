#pragma once
#include "player/RandomAgent.h"
#include "player/FullTreeAgent.h"

class AgentLogic {
  //RandomAgent players[2];
  //bool currentplayer = true;
  FullTreeAgent agent;
 public:
  AgentLogic() {};
  void initialise();
  void update();
  ~AgentLogic();
};

