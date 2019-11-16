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

    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) override;
    void DrawThePath( std::vector< size_t > path ) override;
    void OnMetaChanged( const Meta & meta ) override;
    void OnMetaAdded( const Meta & meta ) override;
    void OnMetaRemoved( const Meta & meta ) override;
    void OnConnectionAdded( const GraphConnection & connection ) override;
    void OnConnectionRemoved( const GraphConnection & connection ) override;

    // запрашивает выбранную ноду
    size_t GetSelectedNode() const override;
    // запрашивает пару для соединения
    std::pair< size_t, size_t > GetSelectedNodes() const override;
    // запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
    QPoint GetNodeCoordinates() const override;
    // запрашивает текущий этаж
    int8_t GetFloorNumber() const override;
};
} // namespace Polaris

#endif // CVIEW_H
