#ifndef MAINAPP_ITEM_CONTROLLER_H
#define MAINAPP_ITEM_CONTROLLER_H

#include "include/graphic_item.h"
#include "include/graphic_room.h"
#include <QGraphicsScene>
#include <QMouseEvent>

namespace Polaris
{
    class ItemController : public QGraphicsScene
    {
    public:
        explicit ItemController( const QRect & scene_rect, QObject * parent = nullptr );
        ~ItemController();

        size_t GetCurrentNode() const;
        size_t GetPreviousNode() const;
        QPointF GetMarkDownPos() const;
        virtual void SetCurPath( std::vector< GraphicItem * > & cur_path );
        virtual void mousePressEvent( QGraphicsSceneMouseEvent * mouse_event ) override;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * mouse_event ) override;
        void ResetCurrentNode();
        void ResetPreviousNode();
    private:
        GraphicItem * current_node_;
        GraphicItem * previous_node_;
        GraphicRoom mark_down_;
        std::vector< GraphicItem * > cur_path_;
        bool path_drawn_;

        void SelectCurrentNode(GraphicItem * const new_current );
        void SelectPreviousNode(GraphicItem * const new_previous );
        void ResetPath();
    };
} // namespace Polaris

#endif //MAINAPP_ITEM_CONTROLLER_H