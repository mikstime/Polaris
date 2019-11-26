#ifndef GRAPHELEMENT_HPP
#define GRAPHELEMENT_HPP

#include "typedefs.h"
namespace Polaris
{
/******************************************************************************
 * GraphElement class generates uuid for each element in model.
 *****************************************************************************/
class GraphElement
{
private:
    Id id_;
public:
    /**************************************************************************
     * GraphElement constructor. Creates uuid.
     * id never equals to 0
     *************************************************************************/
    GraphElement();
    /**************************************************************************
     * GraphElement copy constructor. Copies id.
     *************************************************************************/
     GraphElement( const GraphElement & g ) = default;
    /**************************************************************************
    * GraphElement mode constructor.
    *************************************************************************/
     GraphElement( GraphElement && g ) = default;
    /**************************************************************************
    * GraphElement mode constructor.
    *************************************************************************/
    ~GraphElement() = default;
    /**************************************************************************
     * GetId - returns id of element
     *************************************************************************/
    Id GetId() { return id_; };
};
}//namespace Polaris

#endif //GRAPHELEMENT_HPP
