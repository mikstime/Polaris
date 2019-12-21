#ifndef MAINAPP_GRAPHPARSER_H
#define MAINAPP_GRAPHPARSER_H

#include "include/item_controller.h"
#include "GraphConnection/GraphConnection.h"
#include "Meta/Meta.h"

namespace Polaris
{
/**
 * Обрабатывает запросы от модели, выполняет создание графических элементов по их представлению в модели
 */
class GraphParser
{
public:
    explicit GraphParser() = default;

    /**
     * @param item_controller - указатель на контроллер графических элементов, владеющий ими
     * @param items_in_controller - указатель на структуру, хранящую соответствие указателя на элемент и его айди
     */
    explicit GraphParser( const std::shared_ptr< ItemController > & item_controller,
                          const std::shared_ptr< ItemCollection > & items_in_controller );
    ~GraphParser();
    GraphParser( const GraphParser & ) = delete;
    GraphParser( const GraphParser && ) = delete;
    GraphParser & operator = ( const GraphParser & ) = delete;
    GraphParser & operator = ( const GraphParser && ) = delete;

    /**
     * Добавляет на карту элементы, используется при инициализации новой карты
     * @param meta - информация о комнатах
     * @param graph - информация о соединениях
     */
    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph );

    /**
     * Выделяет помещения на пути
     * @param nodes - помещения
     * @param connections - соединения
     */
    void DrawThePath( const std::vector< Meta > & nodes,
                              const std::vector< GraphConnection > & connections );

    /**
     * Вызывается при изменении информации о помещении в модели
     * @param meta - информация о помещении
     */
    void OnRoomChanged( const Meta & meta );

    /**
     * Вызывается при создании помещения в модели
     * @param meta - информация о помещении
     */
    void OnRoomAdded( const Meta & meta );

    /**
     * Вызывается при удалении помещения из модели
     * @param meta - информация о помещении
     */
    void OnRoomRemoved( const Meta & meta );

    /**
     * Вызывается при создании перехода в модели
     * @param connection - информация о переходе
     */
    void OnConnectionAdded( const GraphConnection & connection );

    /**
     * Вызывается при удалении перехода из модели
     * @param connection - информация о переходе
     */
    void OnConnectionRemoved( const GraphConnection & connection );

private:
    std::shared_ptr< ItemController >item_controller_;
    std::shared_ptr< ItemCollection > items_in_controller_;

    bool EraseItem( const Id id );

};
} // namespace Polaris

#endif //MAINAPP_GRAPHPARSER_H