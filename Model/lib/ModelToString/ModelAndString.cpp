#include "include/ModelToString/ModelAndString.h"

std::string Polaris::ModelAndString::toString( Polaris::Model & m ) {

    std::stringstream s;
    // graph to string
    auto g = m.graph.getGraph();
    s << g.connections.size() << std::endl;
    for( const auto & e : g.connections )
    {
        s << e.second.GetId() << std::endl << e.second.from  << std::endl <<
        e.second.to << std::endl << e.second.cost << std::endl;
    }
    s << g.nodes.size() << std::endl;
    for( const auto & e : g.nodes )
    {
        s << e.GetId() << std::endl;
        s << e.neighbors.size() << std::endl;
        for( const auto & n : e.neighbors )
        {
            s << n << std::endl;
        }
    }
    // meta
    s << m.meta.size() << std::endl;
    for( const auto & me_ : m.meta )
    {
        auto me = me_.second;
        s << me.graph_node_id << std::endl <<
             me.room_number << std::endl <<
             me.info << std::endl <<
             me.coordinates.x() << std::endl <<
             me.coordinates.y() << std::endl;
        s << me.size.size() << std::endl;

        for( auto it : me.size )
            s << it.x() << std::endl << it.y() << std::endl;

        s << me.floor << std::endl;

        switch( me.role )
        {
            case( Role::MARK ): s << "MARK" << std::endl; break;
            case( Role::ROOM ): s << "ROOM" << std::endl; break;
            case( Role::HALL ): s << "HALL" << std::endl; break;
            case( Role::STAIR ): s << "STAIR" << std::endl; break;
            case( Role::CONNECTION ): s << "CONNECTION" << std::endl; break;
            case( Role::POLYGON ): s << "POLYGON" << std::endl; break;
            default: s << "MARK" << std::endl; break;
        }
    }
    return s.str();
}


Polaris::Model Polaris::ModelAndString::fromString( const std::string & str ) {

    std::stringstream s;
    s << str;
//    s.ignore (7777, ' ');
//    s.ignore (7777, '\0');
    Model m;
    //graph
    int cons_size = 0, nodes_size = 0, meta_size = 0;
    s >> cons_size;
    for( int i = 0; i < cons_size; i++ )
    {
        Id id, from, to;
        Price cost;
        s >> id >> from >> to >> cost;
        GraphConnection c( from, to, cost, id );
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
        s >> me.graph_node_id;
        std::getline( s, me.room_number );
        std::getline( s, me.room_number );
        std::getline( s, me.info );

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
        s >> std::skipws >> a;

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