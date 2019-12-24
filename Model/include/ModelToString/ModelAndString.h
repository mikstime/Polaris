#ifndef MAINAPP_MODELANDSTRINGN_H
#define MAINAPP_MODELANDSTRINGN_H

#include <string>
#include "include/Model/Model.h"
#include <Meta/Meta.h>
#include <sstream>
namespace Polaris
{
class ModelAndString
{
    static std::string toString( Model & );
    static Model fromString( const std::string & );
};
}

#endif //MAINAPP_MODELTOSTRINGN_H
