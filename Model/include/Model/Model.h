#ifndef GRAPHSEARCH_MODEL_HPP
#define GRAPHSEARCH_MODEL_HPP

#include "include/Graph/Graph.h"
#include "Meta/Meta.h"
#include <map>
#include <utility>
#include <include/GraphInterface/GraphInterface.h>
#include "typedefs.h"

namespace Polaris
{
struct Meta;
struct Graph;
/******************************************************************************
 * Model structure is used for storing data about the room graph
 * and it's meta information. All logic is provided in ModelInterface.
 *****************************************************************************/
class Model
{
public:
    GraphInterface graph;
    std::map< Id, Meta > meta;
public:
    explicit Model(Graph a_graph = Graph())
    : graph(std::move(a_graph)), meta() {};
    Model( Model const & ) = default;
    Model( Model && ) noexcept = default;
    ~Model() = default;
};
} //namespace Polaris

#endif //GRAPHSEARCH_MODEL_HPP
