#pragma once

#include "feature_flag_set.hpp"


//
// Define flag set for each flag.
//
#define FF(tier, index, name) \
   DECLARE_FLAG(feature_flag_set, FF_##name, tier, index)
#include "feature_flag_list.hpp"
#undef FF
