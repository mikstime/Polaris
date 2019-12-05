#ifndef MAINAPP_CONTROLLER_H
#define MAINAPP_CONTROLLER_H

#include <utility>
#include "typedefs.h"

namespace Polaris
{

class Controller
{
public:
    Controller();
    virtual void AddNode( std::pair< int, int > node_coords ) = 0;
    virtual void AddConnection( Polaris::Id a_node_id, Polaris::Id b_node_id ) = 0;
    virtual void DeleteNode( Polaris::Id node_id ) = 0;
    virtual void DeleteConnection( Polaris::Id a_node_id, Polaris::Id b_node_id ) = 0;
    virtual void MoveNode( Polaris::Id node_id, std::pair< int, int > node_coords ) = 0;
    virtual void ChangeNode( Polaris::Id node_id ) = 0;
    virtual void FindRoute( Polaris::Id a_node_id, Polaris::Id b_node_id ) = 0;
    virtual void ChangeFloor( int floor_number ) = 0;

private:
};

} // namespace Polaris

#endif //MAINAPP_CONTROLLER_H
