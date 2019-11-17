#include "include/GraphElement/GraphElement.h"
#include <cstddef>

using namespace Polaris;
using ID = size_t;

GraphElement::GraphElement()
{
    static ID cur_id = 0;
    id_ = cur_id++;
}