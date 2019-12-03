#ifndef MAINAPP_VIEW_SUB_H
#define MAINAPP_VIEW_SUB_H

#include <vector>
#include "CView/include/view.h"
// TODO временный путь до заголовочных файлов
// TODO подключить заголовочный файл сабскрайбера
#include "Meta/Meta.h"
#include "GraphConnection/GraphConnection.h"
#include "GraphNode/GraphNode.h"

namespace Polaris
{
// TODO наследование
class ViewSub
{
public:
    explicit ViewSub( View * view );
    ViewSub( const ViewSub & ) = delete;
    ViewSub( const ViewSub && ) = delete;
    ViewSub & operator = ( const ViewSub & ) = delete;
    ViewSub & operator = ( const ViewSub && ) = delete;
    ~ViewSub() = default;

    void onPathFound( const std::vector< const GraphNode > & nodes,
                      const std::vector< const GraphConnection > & connections ) ;
    void onMetaChanged( const Meta & meta ) ;
    void onMetaAdded(const Meta & meta ) ;
    void onMetaRemoved(const Meta & meta ) ;
    void onConnectionAdded( const GraphConnection & connection ) ;
    void onConnectionRemoved( const GraphConnection & connection ) ;
    void onNodeAdded( const GraphNode & node ) ;
    void onNodeRemoved( const GraphNode & node ) ;
private:
    View * view_;

};
} // namespace Polaris

#endif //MAINAPP_VIEW_SUB_H
