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

    void DrawThePath( QVector< size_t > ) override;
    void BuildItems( const Meta & meta, const GraphConnection & connection ) override;
    void RefreshItems( const Meta & meta, QVector< size_t > change_list) override;

public slots:
    void GetSelectedNode() const override;
    void GetSelectedNodes() const override;
    void GetNodeCoordinates() const override;
    void GetFloorNumber() const override;

signals:
    void SetSelectedNode( const size_t node_id ) const override;
    void SetSelectedNodes( const size_t a_node_id, const size_t b_node_id ) const override;
    void SetNodeCoordinates( const QPoint point ) const override;
    void SetFloorNumber( const short int floor ) const override;
};
} // namespace Polaris

#endif // CVIEW_H
