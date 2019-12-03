#ifndef MAINAPP_RENDERER_H
#define MAINAPP_RENDERER_H

#include <QGraphicsView>

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

        short int GetFloor() const;
        void wheelEvent( QWheelEvent * event ) override;
//        void mousePressEvent( QMouseEvent * event ) override;
//        void mouseMoveEvent( QMouseEvent * event ) override;

    private:
        int8_t current_floor_;
        bool empty_last_floor_;
        bool empty_first_floor_;

        bool ChangeFloor( const int8_t & step );
        bool FloorEmpty();
        void RaiseEmptyFloor();
    };
} // namespace Polaris

#endif //MAINAPP_RENDERER_H
