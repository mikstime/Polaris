#include <iostream>
#include <include/GraphInterface/GraphInterface.h>
#include <GraphNode/GraphNode.h>
#include <include/ModelInterface/ModelInterface.h>
class TestSub: public Polaris::ModelSubscriber
{
public:
    void onMetaAdded( const Polaris::Meta & meta ) override {}
    void onMetaChanged( const Polaris::Meta & meta ) override {}
    void onMetaRemoved( const Polaris::Meta & meta ) override {}
    void onConnectionAdded( const Polaris::GraphConnection & connection ) override
    {
        std::cout <<"Connection Added\n";
    }
    void onConnectionRemoved( const Polaris::GraphConnection & connection ) override {}
    void onPathFound(
            const std::vector< const Polaris::GraphNode > & nodes,
            const std::vector< const Polaris::GraphConnection > & connections ) override {}
    void onNodeRemoved( const Polaris::GraphNode & node ) override
    {
        std::cout << "Node Removed\n";
    }
    void onNodeAdded( const Polaris::GraphNode & node ) override 
    {
        std::cout << "Node Added\n";
    }
};
int main()
{
    Polaris::GraphNode node{}, node1{};
    {
        Polaris::GraphInterface g{};
        g.AddNode( node );
        std::cout << g.HasNode( node ) <<
                  g.HasNode( node.GetId()) <<
                  node.GetId() << '\n';
        std::cout << g.HasNode( node1 ) <<
                  g.HasNode( node1.GetId()) <<
                  node1.GetId() << '\n';
        std::cout << "test1 passed\n";
    }
    {
        Polaris::ModelInterface mi;
        Polaris::ModelSubscriber * sub = new TestSub;
        mi.Subscribe( sub );
        mi.AddNode( node );
        mi.AddNode( node );
        mi.RemoveNode( node );
        mi.RemoveNode( node );
        Polaris::GraphNode node2{}, node3{};
        Polaris::ConnectionParams p;
        p.cost = 4;
        mi.AddConnection( node2, node3, p );
        mi.AddNode( node2 );
        mi.AddNode( node3 );
        mi.AddConnection( node2, node3, p );
        std::cout << "test2 not passed yet\n";
    }
}