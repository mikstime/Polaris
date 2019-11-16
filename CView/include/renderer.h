#ifndef MAINAPP_RENDERER_H
#define MAINAPP_RENDERER_H

#include <QGraphicsView>

namespace Polaris
{
    class Renderer : public QGraphicsView
    {
    public:
        explicit Renderer( QWidget * parent = nullptr );
        ~Renderer() = default;
        Renderer( const Renderer & ) = delete;
        Renderer( const Renderer && ) = delete;
        Renderer & operator = ( const Renderer & ) = delete;
        Renderer & operator = ( const Renderer && ) = delete;

        short int GetFloor() const;
        void wheelEvent( QWheelEvent * event ) override;

    private:
        short int currnet_floor_;
    };
} // namespace Polaris

#endif //MAINAPP_RENDERER_H
