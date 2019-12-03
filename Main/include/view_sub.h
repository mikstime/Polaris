#ifndef MAINAPP_VIEW_SUB_H
#define MAINAPP_VIEW_SUB_H

#include <vector>
#include "CView/include/view.h"
// TODO временный путь до заголовочных файлов
// TODO подключить заголовочный файл сабскрайбера
#include "../Utils/Meta/Meta.h"
#include "../Utils/GraphConnection/GraphConnection.h"
#include "../Utils/GraphNode/GraphNode.h"
#include "../Model/include/ModelSubscriber/ModelSubscriber.h"

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

    void onPathFound( const std::vector< const GraphNode > & nodes,
                      const std::vector< const GraphConnection > & connections ) override;
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
