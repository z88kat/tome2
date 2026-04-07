#pragma once

#include "ego_flag_set.hpp"


//
// Define flag set for each flag.
//
#define ETR(tier, index, name) \
   DECLARE_FLAG(ego_flag_set, ETR_##name, tier, index)
#include "ego_flag_list.hpp"
#undef ETR
