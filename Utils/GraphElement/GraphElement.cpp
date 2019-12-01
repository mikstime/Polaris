#include "GraphElement/GraphElement.h"
#include "typedefs.h"
Polaris::GraphElement::GraphElement()
{
    //@TODO cool uuid generation
    static Id uuid = 0;
    id_ = ++uuid;
}