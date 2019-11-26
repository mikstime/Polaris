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
     GraphElement( const GraphElement & g ){ id_ = g.id_; };
    /**************************************************************************
    * GraphElement mode constructor.
    *************************************************************************/
     GraphElement( GraphElement && g ) noexcept { id_ = g.id_; };
    /**************************************************************************
    * GraphElement mode constructor.
    *************************************************************************/
    ~GraphElement() = default;
    /**************************************************************************
     * GraphElement constructor. Uses argument as an id.
     * id shouldn't equal to zero.
     *************************************************************************/
    explicit GraphElement(const Id & id): id_( id ) {};
    /**************************************************************************
     * GetId - returns id of element
     *************************************************************************/
    [[nodiscard]] Id GetId() const { return id_; };
};
}//namespace Polaris

#endif //GRAPHELEMENT_HPP
