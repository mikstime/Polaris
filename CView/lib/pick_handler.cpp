#include "include/pick_handler.h"
#include <QDebug>
using Polaris::PickHandler;

PickHandler::PickHandler()
: pics_( 3, QPixmap() )
{
    pics_[ 0 ] = QPixmap( "../pics/door.png" );
    pics_[ 1 ] = QPixmap( "../pics/hall.png" );
    pics_[ 2 ] = QPixmap( "../pics/stair.png" );
}

PickHandler::~PickHandler()
{
}

QPixmap PickHandler::GetDoorPic() const
{
    return pics_[ 0 ];
}

QPixmap PickHandler::GetHallPic() const
{
    return pics_[ 1 ];
}

QPixmap PickHandler::GetStairPic() const
{
    return pics_[ 2 ];
}