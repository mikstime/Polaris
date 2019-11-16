#ifndef MAINAPP_VIEW_H
#define MAINAPP_VIEW_H

struct Meta{};

namespace Polaris
{
    class View
    {
    public:
        virtual ~View() = 0;

        virtual void DrawThePath( QVector< size_t > ) = 0;
        virtual void BuildItems( const Meta & meta, const GraphConnection & connection ) = 0;
        virtual void RefreshItems( const Meta & meta, QVector< size_t > change_list) = 0;

    public slots:
        virtual void GetSelectedNode() const = 0;
        virtual void GetSelectedNodes() const = 0;
        virtual void GetNodeCoordinates() const = 0;
        virtual void GetFloorNumber() const = 0;

    signals:
        virtual void SetSelectedNode( const size_t node_id ) const = 0;
        virtual void SetSelectedNodes( const size_t a_node_id, const size_t b_node_id ) const = 0;
        virtual void SetNodeCoordinates( const QPoint point ) const = 0;
        virtual void SetFloorNumber( const short int floor ) const = 0;
    };
} // namespace Polaris

#endif //MAINAPP_VIEW_H
