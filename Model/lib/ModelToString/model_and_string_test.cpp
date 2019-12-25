#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <include/ModelInterface/ModelInterface.h>
#include <include/ModelToString/ModelAndString.h>
using namespace Polaris;

TEST( ModelAndString, simpleTest1 )
{
    ModelInterface m;
    GraphNode n;

    m.AddNode( n );

    std::string s = ModelAndString::toString( const_cast<Model &>(m.getModel()));
    auto m2 = ModelAndString::fromString( s );
    std::string s2 = ModelAndString::toString( m2 );
    EXPECT_EQ( s, s2 );
}
TEST( ModelAndString, simpleTest2 )
{
    ModelInterface m;
    GraphNode n1, n2, n3, n4;

    m.AddNode( n1 );
    m.AddNode( n2 );
    m.AddNode( n3 );
    m.AddNode( n4 );

    std::string s = ModelAndString::toString( const_cast<Model &>(m.getModel()));
    auto m2 = ModelAndString::fromString( s );
    std::string s2 = ModelAndString::toString( m2 );
    EXPECT_EQ( s, s2 );
}
TEST( ModelAndString, simpleTest3 )
{
    ModelInterface m;
    GraphNode n1, n2;
    ConnectionParams c;
    c.cost = 123;
    m.AddNode( n1 );
    m.AddNode( n2 );
    m.AddConnection( n1, n2, c );

    std::string s = ModelAndString::toString( const_cast<Model &>(m.getModel()));
    auto m2 = ModelAndString::fromString( s );
    std::string s2 = ModelAndString::toString( m2 );
    EXPECT_EQ( s, s2 );
}
TEST( ModelAndString, oneconnection )
{
    ModelInterface m;
    GraphNode n1, n2;
    ConnectionParams c;
    c.cost = 123;
    m.AddNode( n1 );
    m.AddNode( n2 );
    m.AddConnection( n1, n2, c );
    Meta meta;
    meta.info = "Sample info";
    meta.room_number = "448 b";
    meta.role = Role::HALL;
    meta.floor = 4;
    meta.coordinates = QPoint( 10, 20 );
    for( int i = 0; i < 20; i++ )
        meta.size.push_back( QPoint( random() % 100, random() % 150 ) );
    meta.graph_node_id = n1.GetId();
    m.ChangeMeta( n1.GetId(), meta );
    std::string s = ModelAndString::toString( const_cast<Model &>(m.getModel()));
    auto m2 = ModelAndString::fromString( s );
    std::string s2 = ModelAndString::toString( m2 );
    EXPECT_EQ( s, s2 );
}
TEST( ModelAndString, hardTest1 )
{
    ModelInterface m;
    GraphNode n1, n2, n3, n4;
    ConnectionParams c1, c2, c3, c4;
    c1.cost = 1;
    c2.cost = 2;
    c3.cost = 3;
    c4.cost = 4;
    m.AddNode( n1 );
    m.AddNode( n2 );
    m.AddNode( n3 );
    m.AddNode( n4 );

    m.AddConnection( n1, n2, c1 );
    m.AddConnection( n2, n3, c2 );
    m.AddConnection( n3, n4, c3 );
    m.AddConnection( n4, n1, c4 );

    m.AddConnection( n1, n3, c1 );
    m.AddConnection( n2, n4, c2 );
    m.AddConnection( n3, n1, c3 );
    m.AddConnection( n4, n2, c4 );

    std::string s = ModelAndString::toString( const_cast<Model &>(m.getModel()));
    auto m2 = ModelAndString::fromString( s );
    std::string s2 = ModelAndString::toString( m2 );
    EXPECT_EQ( s, s2 );
}
TEST( ModelAndString, hardTest2 )
{
    ModelInterface m;
    GraphNode n1, n2, n3, n4;
    ConnectionParams c1, c2, c3, c4;
    c1.cost = 1;
    c2.cost = 2;
    c3.cost = 3;
    c4.cost = 4;
    m.AddNode( n1 );
    m.AddNode( n2 );
    m.AddNode( n3 );
    m.AddNode( n4 );

    m.AddConnection( n1, n2, c1 );
    m.AddConnection( n2, n3, c2 );
    m.AddConnection( n3, n4, c3 );
    m.AddConnection( n4, n1, c4 );

    m.AddConnection( n1, n3, c1 );
    m.AddConnection( n2, n4, c2 );
    m.AddConnection( n3, n1, c3 );
    m.AddConnection( n4, n2, c4 );
    Meta meta;
    meta.graph_node_id = n1.GetId();
    meta.room_number = "302b";
    meta.floor = 2;
    meta.role = Role::ROOM;
    m.ChangeMeta( n1.GetId(), meta );
    std::string s = ModelAndString::toString( const_cast<Model &>(m.getModel()));
    auto m2 = ModelAndString::fromString( s );
    std::string s2 = ModelAndString::toString( m2 );
    EXPECT_EQ( s, s2 );
    EXPECT_EQ( m.getModel().meta, m2.meta );
    EXPECT_EQ( m.getModel().graph.getGraph().connections, m2.graph.getGraph().connections );
    EXPECT_EQ( m.getModel().graph.getGraph().nodes, m2.graph.getGraph().nodes );
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}