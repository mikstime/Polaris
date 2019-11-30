#ifndef MAINAPP_VIEW_SUB_H
#define MAINAPP_VIEW_SUB_H

#include <vector>
#include "../CView/include/view.h"
// TODO временный путь до заголовочных файлов
// TODO подключить заголовочный файл сабскрайбера
#include "../Utils/Meta/Meta.h"
#include "../Utils/GraphConnection/GraphConnection.h"
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

    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) override;
    void onPathFound( const std::vector< const GraphNode > & nodes,
                      const std::vector< const GraphConnection > & connections ) override;
    void OnMetaChanged( const Meta & meta ) override;
    void OnMetaAdded(const Meta & meta ) override;
    void OnMetaRemoved(const Meta & meta ) override;
    void OnConnectionAdded( const GraphConnection & connection ) override;
    void OnConnectionRemoved( const GraphConnection & connection ) override;
    void onNodeAdded( const GraphNode & node ) override;
    void onNodeRemoved( const GraphNode & node ) override;
private:
    View * view_;

};
} // namespace Polaris

#endif //MAINAPP_VIEW_SUB_H
