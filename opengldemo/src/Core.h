#pragma once

#define TO_STRING(value) #value
#define TAG(clazz) typeid(clazz).name()
#define BIND_FUNCTION(fn) std::bind(&fn, this, std::placeholders::_1)