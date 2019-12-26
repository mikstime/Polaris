#ifndef GRAPHCONNECTION_HPP
#define GRAPHCONNECTION_HPP

#include "typedefs.h"
#include "GraphElement/GraphElement.h"

namespace Polaris
{
/******************************************************************************
 * ConnectionParams structure is used for passing connection's params as an
 * argument
 *****************************************************************************/
struct ConnectionParams
{
    Price cost;
    /**************************************************************************
     * ConnectionParams constructor - set cost to 0.
     *************************************************************************/
    ConnectionParams(): cost( 0 ) {};
    /**************************************************************************
     * ConnectionParams copy constructor
     *************************************************************************/
    ConnectionParams( const ConnectionParams & ) = default;
    /**************************************************************************
     * ConnectionParams move constructor
     *************************************************************************/
    ConnectionParams( ConnectionParams && ) = default;
    /**************************************************************************
     * ConnectionParams default destructor
     *************************************************************************/
    ~ConnectionParams() = default;
};
/******************************************************************************
 * GraphConnection structure is used for storing data about connection
 * between nodes in graph.
 *****************************************************************************/
struct GraphConnection: public GraphElement
{
public:
    Id from, to;
    Price cost;
public:
    explicit GraphConnection( Id id ): GraphElement( id ),
    from( 0 ), to( 0 ), cost( 0 ) {};
    /**************************************************************************
     * GraphConnection default constructor. Initializes all variables to 0.
     *************************************************************************/
    GraphConnection(): GraphElement(), from( 0 ), to( 0 ), cost( 0 ) {};
    /**************************************************************************
     * GraphConnection copy constructor.
     *************************************************************************/
    GraphConnection( const GraphConnection & c ): GraphElement( c.GetId() ),
    to ( c.to ), from( c.from ), cost( c.cost ) {};
    /**************************************************************************
     * GraphConnection move constructor.
     *************************************************************************/
//    GraphConnection( GraphConnection && c ) noexcept: GraphElement( c.GetId() )
//    { to = c.to; from = c.from; cost = c.cost; };
    /**************************************************************************
     * Default destructor.
     *************************************************************************/
    ~GraphConnection() = default;
    /**************************************************************************
     * Build Connection from it's params.
     *************************************************************************/
    GraphConnection( const Id & a_from,
                              const Id & a_to,
                              const ConnectionParams & );
    /**************************************************************************
     * Pass connection properties directly to constructor.
     *************************************************************************/
    GraphConnection( const Id & a_from, const Id & a_to,
                     const Price & a_cost );
    GraphConnection( const Id & a_from, const Id & a_to,
                     const Price & a_cost, const Id & self_id );

    friend bool operator==(
            const GraphConnection & a, const GraphConnection & b )
    {
        return a.GetId() == b.GetId() &&
               a.from == b.from &&
               a.to == b.to &&
               a.cost == b.cost;
    }
};
} //namespace Polaris

#endif //GRAPHCONNECTION_HPP
