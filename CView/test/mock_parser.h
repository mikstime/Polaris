#ifndef MAINAPP_MOCK_PARSER_H
#define MAINAPP_MOCK_PARSER_H

#include "gmock/gmock.h"
#include "include/graph_parser.h"

using Polaris::GraphParser;
using Polaris::Meta;
using Polaris::GraphConnection;

class MockGraphParser : GraphParser
{
public:
    MOCK_METHOD2( BuildItems, void( const std::vector< Meta > & nodes,
                                     const std::vector< GraphConnection > & connections ) );
    MOCK_METHOD2( DrawThePath, void( const std::vector< Meta > & nodes, 
                                     const std::vector< GraphConnection > & connections ) );
    MOCK_METHOD1( OnRoomChanged, void( const Meta & meta ) );
    MOCK_METHOD1( OnRoomAdded, void( const Meta & meta ) );
    MOCK_METHOD1( OnRoomRemoved, void( const Meta & meta ) );
    MOCK_METHOD1( OnConnectionAdded, void( const GraphConnection & connection ) );
    MOCK_METHOD1( OnConnectionRemoved, void( const GraphConnection & connection ) );

};

#endif //MAINAPP_MOCK_PARSER_H