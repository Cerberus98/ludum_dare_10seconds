#ifndef SCOUNDREL_GAMEMAP
#define SCOUNDREL_GAMEMAP

#include <iostream>
#include <list>
#include <string>
#include <sstream>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "animation.h"
#include "level_loader.h"
#include "tile.h"
#include "tile_helper.h"

class GameMap {
public:
  GameMap(TileHelper* tile_helper);
  ~GameMap();
  Tile* get_tile(int x, int y);
  void load_level(int level, Player* player, Camera* camera, Animation* animations, Animation* tile_animations,
                  sf::Sound* sounds, std::list<Entity *>&game_entities);
  void draw(sf::RenderWindow* window, Point camera_pos, Point draw_start, Point draw_end);
  void clear();
  int get_width();
  int get_height();
private:
  int _width, _height;
  TileHelper* _tile_helper;
  Tile*** _game_map;
};

#endif
