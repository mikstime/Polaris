#ifndef MAINAPP_VIEW_H
#define MAINAPP_VIEW_H

#include "Meta/Meta.h"
#include "GraphNode/GraphNode.h"
#include "GraphConnection/GraphConnection.h"
#include <QPoint>
#include <QHBoxLayout>

namespace Polaris
{
    class View
    {
    public:
        virtual ~View() = default;

        virtual void InitMap(const std::vector< Meta > & meta,
                             const std::vector< GraphConnection > & graph ) = 0;
        virtual void DrawThePath(const std::vector< Meta > & path,
                                 const std::vector< GraphConnection > & connections ) = 0;
        virtual void ChangeRoom(const Meta & meta ) = 0;
        virtual void AddRoom(const Meta & meta ) = 0;
        virtual void RemoveRoom(const Meta & meta ) = 0;
        virtual void AddConnection(const GraphConnection & connection ) = 0;
        virtual void RemoveConnection(const GraphConnection & connection ) = 0;
        virtual bool FloorUp() = 0;
        virtual bool FloorDown() = 0;
        // запрашивает выбранную ноду
        virtual size_t GetSelectedNode() const = 0;
        // запрашивает пару для соединения
        virtual std::pair< size_t, size_t > GetSelectedNodes() const = 0;
        // запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
        virtual QPointF GetNodeCoordinates() const = 0;
        // запрашивает текущий этаж
        virtual int8_t GetFloorNumber() const = 0;
        // задать выкладку
        virtual void SetLayout( QHBoxLayout * const layout ) = 0;
    };
} // namespace Polaris

#endif //MAINAPP_VIEW_H