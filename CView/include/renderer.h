#ifndef MAINAPP_RENDERER_H
#define MAINAPP_RENDERER_H

#include <QGraphicsView>
#define QT_NO_DEBUG_OUTPUT

namespace Polaris
{
    class Renderer : public QGraphicsView
    {
    public:
        explicit Renderer( QGraphicsScene * scene, QWidget * parent = nullptr );
        ~Renderer() = default;
        Renderer( const Renderer & ) = delete;
        Renderer( const Renderer && ) = delete;
        Renderer & operator = ( const Renderer & ) = delete;
        Renderer & operator = ( const Renderer && ) = delete;

        int8_t GetFloor() const;
        void SetFloor( const int8_t floor );
        bool FloorUp();
        bool FloorDown();
        void wheelEvent( QWheelEvent * event ) override;
//        void mousePressEvent( QMouseEvent * event ) override;
//        void mouseMoveEvent( QMouseEvent * event ) override;

    private:
        int8_t current_floor_;
        int8_t min_floor_;
        int8_t max_floor_;

        bool ChangeFloor( const int8_t step );
        bool RedrawFloor(const int8_t step );
        bool NextFloorEmpty( const int8_t step );
        void RaiseEmptyFloor();
    };
} // namespace Polaris

#endif //MAINAPP_RENDERER_H