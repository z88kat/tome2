#pragma once

#include "monster_race_flag_set.hpp"


//
// Define flag set for each flag.
//
#define RF(tier, index, name) \
   DECLARE_FLAG(monster_race_flag_set, RF_##name, tier, index)
#include "monster_race_flag_list.hpp"
#undef RF
