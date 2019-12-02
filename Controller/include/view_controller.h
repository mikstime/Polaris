#ifndef MAINAPP_VIEW_CONTROLLER_H
#define MAINAPP_VIEW_CONTROLLER_H

#include <QtCore/QObject>
#include <utility>
#include "node_data.h"

namespace Polaris
{

class ViewController : public QObject
{
    Q_OBJECT

public:
    ViewController();

    /**
     * Get node ids
     * @return - Two ids of selected nodes or EMPTY if not selected
     */
    std::pair< int, int > GetNodeIds();
    /**
     * Get node coordinates
     * @return - Two pairs of node coordinates
     */
    std::pair< std::pair< int, int >, std::pair< int, int > > GetNodeCoords();

private:
    int floor_number_;
    NodeData a_node_data_;
    NodeData b_node_data_;

signals:
    void GetSelectedNode();
    void GetSelectedNodes();
    void GetNodeCoordinates();
    void GetFloorNumber();

public slots:
    void SetSelectedNode( int node_id );
    void SetNodeCoordinates( int x, int y );
    void SetNodesCoordinates( int a_x, int a_y, int b_x, int b_y );
};

} // namespace Polaris

#endif //MAINAPP_VIEW_CONTROLLER_H
