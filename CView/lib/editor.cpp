#include "include/editor.h"

using Polaris::Editor;

Editor::Editor( QGraphicsScene * scene )
: scene_( scene )
{

}

Editor::~Editor()
{
    scene_.release();
}

void Editor::InitEditing( std::vector< GraphicPolygon > polygons )
{

}

void Editor::AddPolygon( GraphicPolygon & polygon )
{

}