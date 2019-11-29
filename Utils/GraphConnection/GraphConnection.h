#ifndef GRAPHCONNECTION_HPP
#define GRAPHCONNECTION_HPP

#include "GraphElement/GraphElement.h"
#include "typedefs.h"

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
    /**************************************************************************
     * GraphConnection default constructor. Initializes all variables to 0.
     *************************************************************************/
    GraphConnection(): from( 0 ), to( 0 ), cost( 0 ) {};
    /**************************************************************************
     * GraphConnection copy constructor.
     *************************************************************************/
    GraphConnection( const GraphConnection & c): GraphElement( c.GetId() )
    { to = c.to; from = c.from; cost = c.cost; };
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
};
} //namespace Polaris

#endif //GRAPHCONNECTION_HPP
