#include "include/GraphElement/GraphElement.h"
#include <cstddef>

using namespace Polaris;
using ID = size_t;

GraphElement::GraphElement( GraphElement const &e )
{
    _id = e._id;
}

GraphElement::GraphElement( Polaris::GraphElement && ) noexcept
{

}

GraphElement::GraphElement()
{
    static ID cur_id = 0;
    _id = cur_id++;
}