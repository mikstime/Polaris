#include "GraphConnection.h"

Polaris::GraphConnection::GraphConnection( const Polaris::Id & a_from,
                                           const Polaris::Id & a_to,
                                           const Polaris::ConnectionParams & p )
:GraphElement()
{
    from = a_from;
    to = a_to;
    cost = p.cost;
}

Polaris::GraphConnection::GraphConnection( const Polaris::Id & a_from,
                                           const Polaris::Id & a_to,
                                           const Polaris::Price & a_cost )
:GraphElement()
{
    from = a_from;
    to = a_to;
    cost = a_cost;
}

Polaris::GraphConnection::GraphConnection( const Polaris::Id & a_from,
                                           const Polaris::Id & a_to,
                                           const Polaris::Price & a_cost,
                                           const Polaris::Id & self_id )
:GraphElement( self_id )
{
    from = a_from;
    to = a_to;
    cost = a_cost;
}
