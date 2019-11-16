#ifndef MAINAPP_VIEW_H
#define MAINAPP_VIEW_H

namespace Polaris
{
    class View
    {
    public:
        virtual ~View() = 0;

        virtual void DrawThePath( std::vector< size_t > ) = 0;
        virtual void BuildItems( const Meta & meta, const GraphConnection & connection ) = 0;
        virtual void RefreshItems( const Meta & meta, std::vector< size_t > change_list) = 0;

        // запрашивает выбранную ноду
        virtual size_t GetSelectedNode() const = 0;
        // запрашивает пару для соединения
        virtual std::pair< size_t, size_t > GetSelectedNodes() const = 0;
        // запрашивает место клика по экрану. Используется для перемещения ноды и для создания новой
        virtual QPoint GetNodeCoordinates() const = 0;
        // запрашивает текущий этаж
        virtual short int GetFloorNumber() const = 0;
    };
} // namespace Polaris

#endif //MAINAPP_VIEW_H
