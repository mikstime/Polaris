#ifndef MAINAPP_RENDERER_H
#define MAINAPP_RENDERER_H

#include <QGraphicsView>
#define QT_NO_DEBUG_OUTPUT

namespace Polaris
{
/**
 * Отрисовщик карты, использует элементы из класса контроллера графических элементов
 */
class Renderer : public QGraphicsView
{
public:
    /**
     * @param scene - указатель на контроллер графических элементов (Qt работает только с raw-pointer`ами)
     * @param parent - родительский виджет
     */
    explicit Renderer( QGraphicsScene * scene, QWidget * parent = nullptr );
    Renderer( const Renderer & ) = delete;
    Renderer( const Renderer && ) = delete;
    Renderer & operator = ( const Renderer & ) = delete;
    Renderer & operator = ( const Renderer && ) = delete;
    ~Renderer() = default;

    /**
     * Запрашивает текущий этаж
     * @return - Номер этажа
     */
    int8_t GetFloor() const;

    /**
     * Установить новый минимальный или максимальный этаж
     * @param floor - номер новго этажа
     */
    void SetFloor( const int8_t floor );

    /**
     * Переключить на этаж выше
     * @return - переключено
     */
    bool FloorUp();

    /**
     * Переключить на этаж нижу
     * @return - переключено
     */
    bool FloorDown();

    /**
     * Реакция на скрол мышью
     * @param event - объект, содержащий информацию о действии мышью
     */
    void wheelEvent( QWheelEvent * event ) override;

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