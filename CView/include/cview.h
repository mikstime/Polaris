#ifndef CVIEW_H
#define CVIEW_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

struct Meta;
struct Graph;

struct SGraphNode; // структура, соответсвтующая комнате
struct SGraphConnection; // структура, соответствующая соединению
namespace Polaris 
{

class CGraphicConnection : public QGraphicsLineItem
{

};

class CGraphicRoom : public QGraphicsEllipseItem
{

};

class CGraphicsScene : public QGraphicsScene
{

};

class CGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit CGraphicsView( QWidget *parent = nullptr );

    CGraphicsView() = delete;
    CGraphicsView( const CGraphicsView& ) = delete;
    CGraphicsView& operator=( const CGraphicsView& ) = delete;
    ~CGraphicsView() = default;

private:
    QVector<CGraphicRoom> rooms_;
    QVector<CGraphicConnection> connections_;

signals:
    void SaveNewRoom( SGraphNode & new_room );
    void SaveNewConnection( SGraphConnection & new_connection );

    void ChooseRoom( int room_id );
    void ChooseConnection( int connection_id );

public slots:
    void BuildItems( const Meta & new_meta, const Graph & new_graph );
    void RefreshItems( const Meta & new_meta, const Graph & new_graph,
                       QVector< int > rooms_change_list);

    void DrawThePath( QVector< int > path );

    void CreateNewConnection();
    void CreateNewRoomMeta();
    void ChangeRoomMeta();

};


}

#endif // CVIEW_H
