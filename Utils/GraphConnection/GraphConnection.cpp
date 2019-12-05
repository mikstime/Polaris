#include "GraphConnection.h"

Polaris::GraphConnection::GraphConnection( const Polaris::Id & a_from,
                                           const Polaris::Id & a_to,
                                           const Polaris::ConnectionParams & p )
{
    from = a_from;
    to = a_to;
    cost = p.cost;
}

Polaris::GraphConnection::GraphConnection( const Polaris::Id id,
                                           const Polaris::Id & a_from,
                                           const Polaris::Id & a_to,
                                           const Polaris::Price & a_cost )
: GraphElement( id )
{
    from = a_from;
    to = a_to;
    cost = a_cost;
}
