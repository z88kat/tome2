#pragma once

#include "dungeon_flag_set.hpp"


//
// Define flag set for each flag.
//
#define DF(tier, index, name) \
   DECLARE_FLAG(dungeon_flag_set, DF_##name, tier, index)
#include "dungeon_flag_list.hpp"
#undef DF
