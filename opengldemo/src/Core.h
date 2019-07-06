#pragma once

#define TO_STRING(value) #value
#define TAG(clazz) typeid(clazz).name()
#define BIND_FN(fn) std::bind(&fn, this, std::placeholders::_1)