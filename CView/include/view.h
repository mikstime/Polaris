#ifndef MAINAPP_VIEW_H
#define MAINAPP_VIEW_H

// TODO временный путь до заголовочных файлов
#include "../Utils/Meta/Meta.h"
#include "../Utils/GraphNode/GraphNode.h"
#include "../Utils/GraphConnection/GraphConnection.h"
#include <QPoint>

namespace Polaris
{
    class View
    {
    public:
        virtual ~View() = default;

        virtual void BuildItems( const std::vector< Meta > & meta,
                                 const std::vector< GraphConnection > & graph ) = 0;
        virtual void OnPathFound(const std::vector< const GraphNode > & nodes,
                                 const std::vector< const GraphConnection > & connections ) = 0;
        virtual void OnMetaChanged( const Meta & meta ) = 0;
        virtual void OnMetaAdded( const Meta & meta ) = 0;
        virtual void OnMetaRemoved( const Meta & meta ) = 0;
        virtual void OnConnectionAdded( const GraphConnection & connection ) = 0;
        virtual void OnConnectionRemoved( const GraphConnection & connection ) = 0;

        // запрашивает выбранную ноду
        virtual size_t GetSelectedNode() const = 0;
        // запрашивает пару для соединения
        virtual std::pair< size_t, size_t > GetSelectedNodes() const = 0;
        // запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
        virtual QPointF GetNodeCoordinates() const = 0;
        // запрашивает текущий этаж
        virtual int8_t GetFloorNumber() const = 0;
    };
} // namespace Polaris

#endif //MAINAPP_VIEW_H
