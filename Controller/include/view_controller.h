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
    QPolygonF GetNodeForm();
    /**
     * Get current floor
     * @return - Floor number
     */
    int8_t GetCurrentFloor();
    /**
     * Get node ids
     * @return - Two ids of selected nodes or EMPTY if not selected
     */
    std::pair< int, int > GetNodeIds();
    /**
     * Get node coordinates
     * @return - Two pairs of node coordinates
     */
    QPointF GetNodeCoords();

    //TODO Реализация переключения
    void ChangeMode();
    int GetFloorNumber();
    void FloorUp();
    void FloorDown();

private:
    // Pointer to View object
    GraphicView * view_;

    int floor_number_;

    Id first_node_;
    Id second_node_;

    QPointF coords_;
};

} // namespace Polaris

#endif // VIEW_CONTROLLER_H
