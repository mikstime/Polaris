#ifndef MAINAPP_NODE_DATA_H
#define MAINAPP_NODE_DATA_H

#include <vector>

namespace Polaris
{

struct NodeData
{
    int node_id_;
    std::vector< int > coords_;
};

} // namespace Polaris

#endif //MAINAPP_NODE_DATA_H
