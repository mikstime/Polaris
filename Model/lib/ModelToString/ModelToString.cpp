#include "include/ModelToString/ModelToString.h"

std::string Polaris::ModelToString::toString( Polaris::Model & m ) {

    std::stringstream s;
    // graph to string
    auto g = m.graph.getGraph();
    s << g.connections.size();
    for( const auto & e : g.connections )
    {
        s << e.second.GetId() << e.second.from << e.second.to << e.second.cost;
    }
    s << g.nodes.size();
    for( const auto & e : g.nodes )
    {
        s << e.GetId();
        s << e.neighbors.size();
        for( const auto & n : e.neighbors )
        {
            s << n;
        }
    }
    // meta
    s << m.meta.size();
    for( const auto & me_ : m.meta )
    {
        auto me = me_.second;
        s << me.graph_node_id << me.room_number <<
               me.info << me.coordinates.x() << me.coordinates.y();
        s << me.size.size();

        for( auto it : me.size )
            s << it.x() << it.y();

        s << me.floor;

        switch( me.role )
        {
            case( Role::MARK ): s << "MARK"; break;
            case( Role::ROOM ): s << "ROOM"; break;
            case( Role::HALL ): s << "HALL"; break;
            case( Role::STAIR ): s << "STAIR"; break;
            case( Role::CONNECTION ): s << "CONNECTION"; break;
            case( Role::POLYGON ): s << "POLYGON"; break;
        }
    }
    return s.str();
}


Polaris::Model Polaris::ModelToString::fromString( const std::string & str ) {

    std::stringstream s;
    s << str;
    Model m;
    //graph
    int cons_size = 0, nodes_size = 0, meta_size = 0;
    s >> cons_size;
    for( int i = 0; i < cons_size; i++ )
    {
        Id id, from, to;
        Price cost;
        s >> id >> from >> to >> cost;
        GraphConnection c( id, from, to, cost );
        std::pair< Id, Id > key( from, to );
        m.graph.getGraph().connections[ key ] = c;
    }
    s >> nodes_size;
    for( int i = 0; i < nodes_size; i++ )
    {
        Id id, n_id;
        s >> id;
        GraphNode node( id );
        int n_size = 0;
        s >> n_size;
        for( int j = 0; j < n_size; j++ )
        {
            s >> n_id;
            node.neighbors.emplace_back( n_id );
        }
        m.graph.getGraph().nodes.emplace( node );
    }
    //meta
    s >> meta_size;
    for( int i = 0; i < meta_size; i++ )
    {
        Meta me;
        s >> me.graph_node_id >> me.room_number >> me.info;
        float x, y;
        s >> x >> y;
        QPointF p(x, y );
        me.coordinates = p;
        int s_size = 0;
        s >> s_size;
        for( int j = 0; j < s_size; j++ )
        {
            s >> x >> y;
            me.size.push_back( QPointF( x, y ) );
        }
        s >> me.floor;
        std::string a;
        s >> a;
        if( a == "MARK" )
            me.role = Role::MARK;
        else if( a == "ROOM" )
            me.role = Role::ROOM;
        else if( a == "HALL" )
            me.role = Role::HALL;
        else if( a == "STAIR" )
            me.role = Role::STAIR;
        else if( a == "CONNECTION" )
            me.role = Role::CONNECTION;
        else if( a == "POLYGON" )
            me.role = Role::POLYGON;
        m.meta[ me.graph_node_id ] = me;
    }
    return m;
}