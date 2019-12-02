#ifndef MAINAPP_CONTROLLER_H
#define MAINAPP_CONTROLLER_H

#include <utility>

namespace Polaris
{

class Controller
{
public:
    Controller();
    virtual void AddNode( std::pair< int, int > node_coords ) = 0;
    virtual void AddConnection( int a_node_id, int b_node_id ) = 0;
    virtual void DeleteNode( int node_id ) = 0;
    virtual void DeleteConnection( int a_node_id, int b_node_id ) = 0;
    virtual void MoveNode( int node_id, std::pair< int, int > node_coords ) = 0;
    virtual void ChangeNode( int node_id ) = 0;
    virtual void FindRoute( int a_node_id, int b_node_id ) = 0;
    virtual void ChangeFloor( int floor_number ) = 0;

private:
};

} // namespace Polaris

#endif //MAINAPP_CONTROLLER_H
