#ifndef MAINAPP_VIEW_SUB_H
#define MAINAPP_VIEW_SUB_H

#include <vector>
#include "view.h"
// TODO временный путь до заголовочных файлов
#include "../../Model/include/Meta/Meta.h"
#include "../../Model/include/GraphConnection/GraphConnection.h"

namespace Polaris
{
    // TODO Наследовние от сабскрайбера
class ViewSub
{
public:
    explicit ViewSub( View * view );
    ViewSub( const ViewSub & ) = delete;
    ViewSub( const ViewSub && ) = delete;
    ViewSub & operator = ( const ViewSub & ) = delete;
    ViewSub & operator = ( const ViewSub && ) = delete;
    ~ViewSub() = default;

    void BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) const;
    void DrawThePath( std::vector< size_t > path ) const;
    void OnMetaChanged( const Meta & meta ) const;
    void OnMetaAdded( const Meta & meta ) const;
    void OnMetaRemoved( const Meta & meta ) const;
    void OnConnectionAdded( const GraphConnection & connection ) const;
    void OnConnectionRemoved( const GraphConnection & connection ) const;

private:
    View * view_;

};
} // namespace Polaris

#endif //MAINAPP_VIEW_SUB_H
