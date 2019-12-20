#ifndef MAINAPP_ITEM_CONTROLLER_H
#define MAINAPP_ITEM_CONTROLLER_H

#include "include/editor.h"
#include "include/graphic_room.h"
#include "include/item_collaction.h"
#include <QGraphicsScene>
#include <memory>
#include <QMouseEvent>

namespace Polaris
{
    class ItemController : public QGraphicsScene
    {
    public:
        explicit ItemController( const QRect & scene_rect, std::shared_ptr< ItemCollaction > items_in_controller,
                                 QObject * parent = nullptr );
        ~ItemController();

        size_t GetCurrentNode() const;
        size_t GetPreviousNode() const;
        QPointF GetMarkDownPos() const;
        QPolygonF GetNewForm() const;
        virtual void SetCurPath( std::vector< GraphicItem * > & cur_path );
        void ResetEditing();
        virtual void mousePressEvent( QGraphicsSceneMouseEvent * mouse_event ) override;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * mouse_event ) override;
        void ResetCurrentNode();
        void ResetPreviousNode();
        bool ChangeMode( bool edit );

    private:
        bool is_edit_;
        GraphicItem * current_node_;
        GraphicItem * previous_node_;
        // TODO заменить на смарот поинтер
        GraphicRoom mark_down_;
        std::unique_ptr< Editor > editor_;
        std::shared_ptr< ItemCollaction > items_in_controller_;
        std::vector< GraphicItem * > cur_path_;
        bool path_drawn_;

        void SelectCurrentNode(GraphicItem * const new_current );
        void SelectPreviousNode(GraphicItem * const new_previous );
        void ResetPath();
        void RoomPressedLeft(GraphicItem * const cur_item, const QPointF & cur_pos );
        void EmptyPressedLeft(const QPointF & cur_pos );
        void RoomPressedLeftCtrl(GraphicItem * const cur_item, const QPointF & cur_pos );
        void EmptyPressedLeftCtrl(GraphicItem * const cur_item, const QPointF & cur_pos );
        void EmptyPressedRight(const QPointF & cur_pos );
        void RoomReleaseLeft(GraphicItem * const cur_item, const QPointF & cur_pos );
        void EmptyReleaseLeft(const QPointF & cur_pos );
        void RoomReleaseRight(GraphicItem * const cur_item, const QPointF & cur_pos );
        void EmptyReleaseRight(const QPointF & cur_pos );
    };
} // namespace Polaris

#endif //MAINAPP_ITEM_CONTROLLER_H