#ifndef MAINAPP_NODE_DATA_H
#define MAINAPP_NODE_DATA_H

#include <utility>

#define EMPTY -1

namespace Polaris
{

struct NodeData
{
    int node_id_;
    std::pair< int, int > coords_;
};

} // namespace Polaris

#endif //MAINAPP_NODE_DATA_H
