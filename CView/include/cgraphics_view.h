#ifndef CVIEW_H
#define CVIEW_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "cgraphic_room.h"
#include "cgraphic_connection.h"

namespace Polaris 
{
class CGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit CGraphicsView( QWidget *parent = nullptr );

    CGraphicsView() = delete;
    CGraphicsView( const CGraphicsView & ) = delete;
    CGraphicsView & operator=( const CGraphicsView & ) = delete;
    ~CGraphicsView() = default;

    QVector< CGraphicRoom > & GetRooms();
    QVector< CGraphicConnection > & GetConnections();

private:
    QVector< CGraphicRoom > rooms_;
    QVector< CGraphicConnection > connections_;

signals:
    void SaveNewRoom( GraphNode new_room );
    void SaveNewConnection( GraphConnection new_connection );

    void ChooseRoom( int room_id );
    void ChooseConnection( int connection_id );

public slots:
    void BuildItems( const Meta & new_meta, const Graph & new_graph );
    void RefreshItems( const Meta & new_meta, const Graph & new_graph,
                       QVector< int > rooms_change_list );

    void DrawThePath( QVector< int > path );

    void CreateNewConnection();
    void CreateNewRoomMeta();
    void ChangeRoomMeta();

};
} // namespace Polaris

#endif // CVIEW_H
