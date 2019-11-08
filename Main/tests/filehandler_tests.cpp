#include <gtest/gtest.h>
#include "../include/filehandler.h"

#define GRAPH_SIZE 10
#define FILE_NAME "../test.dat"

TEST( FileHandler, FileWrite )
{
    Polaris::FileHandler file_handler;
    std::vector< GraphNode > graph(GRAPH_SIZE);
    for( int i = 0; i < GRAPH_SIZE; ++i )
    {
        GraphNode node;
        graph[i] = node;
    }
    file_handler.FileWrite(graph, FILE_NAME);

    FILE * file;
    file = fopen(FILE_NAME, "rb");
    for( int i = 0; i < GRAPH_SIZE ; ++i)
    {
        GraphNode node;
        fread( & node, sizeof( GraphNode ), 1, file );
        EXPECT_EQ(0, 0);
    }
}

TEST( FileHandler, FileRead )
{
    Polaris::FileHandler file_handler;
    std::vector< GraphNode > graph;
    file_handler.FileRead( graph, FILE_NAME );

    for( int i = 0; i < GRAPH_SIZE; ++i )
    {
        GraphNode node;
        node = graph[i];
        EXPECT_EQ(0, 0);
    }
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( & argc, argv );
    return RUN_ALL_TESTS();
}
