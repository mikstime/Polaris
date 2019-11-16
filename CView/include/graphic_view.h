#ifndef CVIEW_H
#define CVIEW_H

#include "view.h"
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Polaris 
{
class GraphicView : public View
{

public:
    explicit GraphicView();
    GraphicView( const GraphicView & ) = delete;
    GraphicView( const GraphicView && ) = delete;
    GraphicView & operator = ( const GraphicView & ) = delete;
    GraphicView & operator = ( const GraphicView && ) = delete;
    ~GraphicView() = default;

    void DrawThePath( std::vector< size_t > path ) override;
    void BuildItems( const Meta & meta, const GraphConnection & connection ) override;
    void RefreshItems( const Meta & meta, std::vector< size_t > change_list ) override;

    // запрашивает выбранную ноду
    size_t GetSelectedNode() const;
    // запрашивает пару для соединения
    std::pair< size_t, size_t > GetSelectedNodes() const;
    // запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
    QPoint GetNodeCoordinates() const;
    // запрашивает текущий этаж
    short int GetFloorNumber() const;
};
} // namespace Polaris

#endif // CVIEW_H
