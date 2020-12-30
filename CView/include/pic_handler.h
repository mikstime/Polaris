#ifndef MAINAPP_PIC_HANDLER_H
#define MAINAPP_PIC_HANDLER_H

#include <QtGui/QPixmap>

namespace Polaris
{
/**
 * Знимается загрузкой картинок
 */
    class PickHandler
    {
    public:
        /**
         * Конструктор инициализирует объекты картинок
         */
        explicit PickHandler();
        explicit PickHandler( const PickHandler & ) = delete;
        explicit PickHandler( const PickHandler && ) = delete;
        PickHandler & operator = (const PickHandler & ) = delete;
        PickHandler & operator = ( const PickHandler && ) = delete;
        ~PickHandler();

        QPixmap GetDoorPic() const;
        QPixmap GetHallPic() const;
        QPixmap GetStairPic() const;

    private:
        std::vector< QPixmap > pics_;
    };
} // namespace Polaris

#endif