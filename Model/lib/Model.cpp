#include "include/Model.h"

using namespace Polaris;

Model::Model()
{

}

Model::Model( Polaris::Model && ) noexcept
{

}

Model::Model( const Polaris::Model & )
{

}

Model::~Model()
{

}

void Model::AddNode( const Polaris::GraphNode & )
{

}

void Model::RemoveNode( const Polaris::GraphNode & )
{

}

void Model::AddConnection( const Polaris::GraphNode &,
                           const Polaris::GraphNode & )
{

}

void Model::RemoveConnection( const Polaris::GraphNode &,
                              const Polaris::GraphNode & )
{

}

void Model::ChangeModelMeta( Polaris::GraphNode &, const Meta & )
{

}

void Model::UpdateView()
{

}

void Model::RequestRender()
{

}