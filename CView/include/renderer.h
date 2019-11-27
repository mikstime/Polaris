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

    private:
        int8_t current_floor_;

        void ChangeFloor( const int8_t & step );
    };
} // namespace Polaris

#endif //MAINAPP_RENDERER_H
