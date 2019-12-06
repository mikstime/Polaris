#ifndef VIEW_CONTROLLER_H
#define VIEW_CONTROLLER_H

#include <QtCore/QObject>
#include <utility>

#include "typedefs.h"
#include "include/graphic_view.h"

namespace Polaris
{

class ViewController : public QObject
{
    Q_OBJECT

public:
    /**
     * Constructor
     * @param view - pointer to View object
     */
    explicit ViewController( GraphicView * view );
    /**
     * Update selected nodes data
     */
    void UpdateSelectedNodes();
    /**
     * Update selected node coordinates
     */
    void UpdateNodeCoordinates();
    /**
     * Get node ids
     * @return - Two ids of selected nodes or EMPTY if not selected
     */
    std::pair< int, int > GetNodeIds();
    /**
     * Get node coordinates
     * @return - Two pairs of node coordinates
     */
    std::pair< Coordinate, Coordinate > GetNodeCoords();

private:
    // Pointer to View object
    GraphicView * view_;

    int floor_number_;

    Id first_node_;
    Id second_node_;

    std::pair< Coordinate, Coordinate > coords_;
};

} // namespace Polaris

#endif // VIEW_CONTROLLER_H
