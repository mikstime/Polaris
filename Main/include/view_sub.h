#ifndef MAINAPP_VIEW_SUB_H
#define MAINAPP_VIEW_SUB_H

#include <vector>
#include "include/view.h"
#include "include/ModelSubscriber/ModelSubscriber.h"
// TODO временный путь до заголовочных файлов
// TODO подключить заголовочный файл сабскрайбера

namespace Polaris
{

class ViewSub : public ModelSubscriber
{
public:
    explicit ViewSub( View * view );
    ViewSub( const ViewSub & ) = delete;
    ViewSub( const ViewSub && ) = delete;
    ViewSub & operator = ( const ViewSub & ) = delete;
    ViewSub & operator = ( const ViewSub && ) = delete;
    ~ViewSub() = default;

//    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) override;
    void onPathFound( std::vector< Meta > & nodes,
                      std::vector< GraphConnection > & connections ) override;
    void onMetaChanged( const Meta & meta ) override;
    void onMetaAdded(const Meta & meta ) override;
    void onMetaRemoved(const Meta & meta ) override;
    void onConnectionAdded( const GraphConnection & connection ) override;
    void onConnectionRemoved( const GraphConnection & connection ) override;
    void onNodeAdded( const GraphNode & node ) override;
    void onNodeRemoved( const GraphNode & node ) override;
private:
    View * view_;

};
} // namespace Polaris

#endif //MAINAPP_VIEW_SUB_H
