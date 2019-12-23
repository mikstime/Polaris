#ifndef MAINAPP_VIEW_SUB_H
#define MAINAPP_VIEW_SUB_H

#include "include/view.h"
#include "include/ModelSubscriber/ModelSubscriber.h"
#include <vector>
#include <memory>

namespace Polaris
{
/**
 * Мост между паттерном "Наблюдатель" и "Фасад", то есть между моделью и представлением
 */
class ViewSub : public ModelSubscriber
{
public:
    /**
     * @param view - указатель на представление
     */
    explicit ViewSub( std::shared_ptr< View > view );
    ViewSub( const ViewSub & ) = delete;
    ViewSub( const ViewSub && ) = delete;
    ViewSub & operator = ( const ViewSub & ) = delete;
    ViewSub & operator = ( const ViewSub && ) = delete;
    ~ViewSub() = default;

    /**
     * Инициализировать карту
     * @param meta - информация о помещениях из модели
     * @param graph - информация о переходах из модели
     */
//    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) override;

    /**
     * Выделяет помещения на пути
     * @param nodes - помещения
     * @param connections - соединения
     */
    void onPathFound( std::vector< Meta > & nodes,
                      std::vector< GraphConnection > & connections ) override;

    /**
     * Вызывается при изменении информации о помещении в модели
     * @param meta - информация о помещении
     */
    void onMetaChanged( const Meta & meta ) override;

    /**
     * Вызывается при создании помещения в модели
     * @param meta - информация о помещении
     */
    void onMetaAdded(const Meta & meta ) override;

    /**
     * Вызывается при удалении помещения из модели
     * @param meta - информация о помещении
     */
    void onMetaRemoved(const Meta & meta ) override;

    /**
     * Вызывается при удалении перехода из модели
     * @param connection - информация о переходе
     */
    void onConnectionAdded( const GraphConnection & connection ) override;

    /**
     * Переключить на этаж выше
     * @return - переключено
     */
    void onConnectionRemoved( const GraphConnection & connection ) override;

    /**
     * Вызывается при создании узла в модели
     * @param meta - информация об узле
     */
    void onNodeAdded( const GraphNode & node ) override {};

    /**
     * Вызывается при удалении узла в модели
     * @param meta - информация об узле
     */
    void onNodeRemoved( const GraphNode & node ) override {};

private:
    std::shared_ptr< View > view_;

};
} // namespace Polaris

#endif //MAINAPP_VIEW_SUB_H
