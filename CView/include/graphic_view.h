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

    GraphicView( const QSize & size, QHBoxLayout * const layout, QWidget * parent );

    GraphicView & operator = (const GraphicView & ) = delete;
    GraphicView & operator = ( const GraphicView && ) = delete;
    ~GraphicView() = default;

    void InitMap(const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) override;
    void DrawThePath(const std::vector< Meta > & nodes,
                     const std::vector< GraphConnection > & connections ) override;
    void ChangeRoom(const Meta & meta ) override;
    void AddRoom(const Meta & meta ) override;
    void RemoveRoom(const Meta & meta ) override;
    void AddConnection(const GraphConnection & connection ) override;
    void RemoveConnection(const GraphConnection & connection ) override;
    bool FloorUp() override;
    bool FloorDown() override;
    // запрашивает выбранную ноду
    size_t GetSelectedNode() const override;
    // запрашивает пару для соединения
    std::pair< size_t, size_t > GetSelectedNodes() const override;
    // запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
    QPointF GetNodeCoordinates() const override;
    // запрашивает текущий этаж
    int8_t GetFloorNumber() const override;
    // задать выкладку
    void SetLayout( QHBoxLayout * const layout );
    void SetParser( std::shared_ptr< GraphParser > graphic_parser );

private:
    // TODO будут ли работать указатели?
    std::shared_ptr< ItemController > item_controller_;
    std::shared_ptr< GraphParser > graph_parser_;
    std::shared_ptr< Renderer > renderer_;

};
} // namespace Polaris

#endif // CVIEW_H