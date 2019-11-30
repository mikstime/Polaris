#ifndef CVIEW_H
#define CVIEW_H

#include "include/graph_parser.h"
#include "include/item_controller.h"
#include "view.h"
#include <memory>
#include "renderer.h"
#include <QGraphicsView>
#include <QtWidgets/QVBoxLayout>

namespace Polaris 
{
class GraphicView : public View
{

public:
    explicit GraphicView();
    GraphicView( const GraphicView & ) = delete;
    GraphicView( const GraphicView && ) = delete;

    GraphicView( const QRect & size, QVBoxLayout & layout, QWidget * parent );

    GraphicView & operator = (const GraphicView & ) = delete;
    GraphicView & operator = ( const GraphicView && ) = delete;
    ~GraphicView() = default;

    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) override;
    void OnPathFound(const std::vector< const GraphNode > & nodes,
                     const std::vector< const GraphConnection > & connections ) override;
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
    QPointF GetNodeCoordinates() const override;
    // запрашивает текущий этаж
    int8_t GetFloorNumber() const override;

private:
    // TODO будут ли работать указатели?
    std::shared_ptr< ItemController > item_controller_;
    std::shared_ptr< GraphParser > graph_parser_;
    std::shared_ptr< Renderer > renderer_;

};
} // namespace Polaris

#endif // CVIEW_H
