#ifndef TASK_IF_H_
#define TASK_IF_H_

#include <functional>
#include "Utils.h"

using Task = std::function<Status(void)>;

#endif 