#pragma once

#include "map.h"
#include "cave.h"

class Island : public Map {
  public:

    Tile get_tile(int x, int y) const override;
    void generate(unsigned int seed) override;

    Cave* get_cave(int x, int y);

  private:

    const float NOISE_ZOOM = 0.03f;

    float elevation_z_, moisture_z_;
    std::map<std::pair<int, int>, Cave> caves_;

    float elevation(int x, int y) const;
    float moisture(int x, int y) const;
    float noise(int x, int y, int z) const;

    void place_cave();
    void place_town();
    void place_npc(Character::Role role);

};
