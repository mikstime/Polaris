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
     * Destructor
     */
    ~ViewController();
    /**
     * Copy constructor
     */
    ViewController( const ViewController & ) = delete;
    /**
     * Copy assignment operator
     * @return
     */
    ViewController & operator=( const ViewController & ) = delete;
    /**
     * Update selected nodes data
     */
    void UpdateSelectedNodes();
    /**
     * Update selected node coordinates
     */
    void UpdateNodeCoordinates();
    /**
     * Get node form
     * @return node form
     */
    QPolygonF GetNodeForm();
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
    /**
     * Change app mode
     * @param is_editing - True for edit mode
     */
    void ChangeMode( bool is_editing );
    /**
     * Get current floor number
     * @return - Floor number
     */
    int GetFloorNumber();
    /**
     * Floor up and return floor
     * @return - New floor number
     */
    int FloorUp();
    /**
     * Floor down and return floor
     * @return - New floor number
     */
    int FloorDown();

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
