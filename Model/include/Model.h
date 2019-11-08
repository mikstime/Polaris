//
// Created by MBTSKY on 06.11.2019.
//

#ifndef GRAPHSEARCH_MODEL_HPP
#define GRAPHSEARCH_MODEL_HPP

#include <QObject>
#include "include/Graph/Graph.h"
#include "include/GraphNode/GraphNode.h"
#include "include/Meta/Meta.h"

namespace Polaris
{
class Model: public QObject
{
    Q_OBJECT
public:
    Model();
    Model( Model const & );
    Model( Model && ) noexcept;
    ~Model();
public slots:
    void AddNode( const GraphNode & );
    void RemoveNode( const GraphNode & );
    void AddConnection( const GraphNode &, const GraphNode & );
    void RemoveConnection( const GraphNode &, const GraphNode & );
    void ChangeModelMeta( GraphNode &, const Meta & );
signals:
    void RequestRender( /*Concrete arguments will apear later*/ );
    void UpdateView( /*Array of GraphNode could be used as an argument*/ );
private:
    Graph graph_;
    Meta meta_;
};
} //namespace Polaris

#endif //GRAPHSEARCH_MODEL_HPP
