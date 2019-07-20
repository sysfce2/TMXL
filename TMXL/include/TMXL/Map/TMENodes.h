#ifndef TMXL_TMENODE_H
#define TMXL_TMENODE_H

#include "TMXL/System/ResourceManager.h"
#include "TMXL/System/Color.h"
#include "TMXL/Config.h"
#include "TMXL/Tools.h"

#include <vector>
#include <string>
#include <map>

namespace TMXL {

    enum class MapOrientation {
        Undefined = -1,
        Orthogonal,
        Isometric,
        Staggered,
        Hexagonal
    };

    enum class MapRenderOrder {
        Undefined = -1,
        RightDown,
        RightUp,
        LeftDown,
        LeftUp
    };

    struct ITmeBase { };

    /**
     * @details TMEProperty - Структура хранащая одну единица параметра в разделе properties
     */
    struct TMEProperty : ITmeBase {
        sf::String             name;
        TMXLTypes              type;
        sf::String             value;
    };

    struct TMEImage : ITmeBase {
        Color                  trans;
        std::size_t            width;
        std::size_t            height;
        std::string            image;
    };

    struct TMETileset : ITmeBase {
        sf::String             source;
        sf::String             name;
        std::size_t            firstGID;
        std::size_t            tileWidth;
        std::size_t            tileHeight;
        int                    spacing;
        int                    marign;
        std::size_t            tileCount;
        std::size_t            columns;
    };

    /**
     * @details TMEMap - Структура хранящая основную информацию карты.
     * staggerIndex хранит вместо строки со значением even или odd, первые символы этой строки.
     *              e = even
     *              o = odd
     */
    struct TMEMap : ITmeBase {
        std::size_t            mapWidth;
        std::size_t            mapHeight;
        MapOrientation         mapOrientation        = MapOrientation::Undefined;
        MapRenderOrder         renderOrder           = MapRenderOrder::Undefined;

        Color                  backgroundColor       = Color::White;
        std::size_t            nextObjectId          = 0;
        std::size_t            nextLayerId           = 0;
        std::size_t            hexSideLength         = 0;
        std::size_t            tileWidth             = 0;
        std::size_t            tileHeight            = 0;
        char                   staggerIndex          = '-';
        char                   staggerAxis           = '-';

        std::vector<TMEProperty>                        properties;
    };

}

#endif //TMXL_TMENODE_H
