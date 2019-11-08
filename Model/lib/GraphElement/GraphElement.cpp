#include "include/GraphElement/GraphElement.h"
#include <cstddef>

using namespace Polaris;
using ID = size_t;

GraphElement::GraphElement( GraphElement const &e )
{
    id_ = e.id_;
}

GraphElement::GraphElement( Polaris::GraphElement && ) noexcept
{

}

GraphElement::GraphElement()
{
    static ID cur_id = 0;
    id_ = cur_id++;
}