#pragma once

#define TO_STRING(value) #value
#define BIND_FUNCTION(fn) std::bind(&fn, this, std::placeholders::_1)