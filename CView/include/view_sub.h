#ifndef MAINAPP_VIEW_SUB_H
#define MAINAPP_VIEW_SUB_H

#include <vector>
#include "view.h"
// TODO временный путь до заголовочных файлов
#include "../../Model/include/Meta/Meta.h"
#include "../../Model/include/GraphConnection/GraphConnection.h"


namespace Polaris
{
class ViewSub
{
public:
    explicit ViewSub( View * view );
    ViewSub( const ViewSub & ) = delete;
    ViewSub( const ViewSub && ) = delete;
    ViewSub & operator = ( const ViewSub & ) = delete;
    ViewSub & operator = ( const ViewSub && ) = delete;

    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph );
    void DrawThePath( std::vector< size_t > path );
    void OnMetaChanged( const Meta & meta );
    void OnMetaAdded( const Meta & meta );
    void OnMetaRemoved( const Meta & meta );
    void OnConnectionAdded( const GraphConnection & connection );
    void OnConnectionRemoved( const GraphConnection & connection );

private:
    View * view_;
};
} // namespace Polaris

#endif //MAINAPP_VIEW_SUB_H
