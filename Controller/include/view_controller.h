#ifndef VIEW_CONTROLLER_H
#define VIEW_CONTROLLER_H

#include <QtCore/QObject>
#include <utility>

#include "include/node_data.h"

namespace Polaris
{

class ViewController : public QObject
{
    Q_OBJECT

public:
    /**
     * Constructor
     */
    ViewController();
    /**
     * Update selected nodes data
     */
    void UpdateSelectedNodes();
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
};

} // namespace Polaris

#endif // VIEW_CONTROLLER_H
