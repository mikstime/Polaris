#ifndef MAINAPP_MODELTOSTRINGN_H
#define MAINAPP_MODELTOSTRINGN_H

#include <string>
#include "include/Model/Model.h"
#include <Meta/Meta.h>
#include <sstream>
namespace Polaris
{
class ModelToString
{
    static std::string toString( Model & );
    static Model fromString( const std::string & );
};
}

#endif //MAINAPP_MODELTOSTRINGN_H
