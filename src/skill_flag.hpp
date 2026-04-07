#pragma once

#include "skill_flag_set.hpp"


//
// Define flag set for each flag.
//
#define SKF(tier, index, name) \
   DECLARE_FLAG(skill_flag_set, SKF_##name, tier, index)
#include "skill_flag_list.hpp"
#undef SKF
