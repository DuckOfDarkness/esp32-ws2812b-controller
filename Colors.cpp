#include "Colors.h"

const uint32_t RED = Adafruit_NeoPixel::Color(255, 0, 0);
const uint32_t GREEN = Adafruit_NeoPixel::Color(0, 255, 0);
const uint32_t BLUE = Adafruit_NeoPixel::Color(0, 0, 255);
const uint32_t YELLOW = Adafruit_NeoPixel::Color(255, 255, 0);
const uint32_t CYAN = Adafruit_NeoPixel::Color(0, 255, 255);
const uint32_t MAGENTA = Adafruit_NeoPixel::Color(255, 0, 255);
const uint32_t WHITE = Adafruit_NeoPixel::Color(255, 255, 255);
const uint32_t GRAY = Adafruit_NeoPixel::Color(128, 128, 128);
const uint32_t AQUA = Adafruit_NeoPixel::Color(0, 255, 255);
const uint32_t BEIGE = Adafruit_NeoPixel::Color(245, 245, 220);
const uint32_t CORAL = Adafruit_NeoPixel::Color(255, 127, 80);
const uint32_t CRIMSON = Adafruit_NeoPixel::Color(220, 20, 60);
const uint32_t FUCHSIA = Adafruit_NeoPixel::Color(255, 0, 255);
const uint32_t GOLD = Adafruit_NeoPixel::Color(255, 215, 0);
const uint32_t INDIGO = Adafruit_NeoPixel::Color(75, 0, 130);
const uint32_t IVORY = Adafruit_NeoPixel::Color(255, 255, 240);
const uint32_t KHAKI = Adafruit_NeoPixel::Color(240, 230, 140);
const uint32_t LAVENDER = Adafruit_NeoPixel::Color(230, 230, 250);
const uint32_t LIME = Adafruit_NeoPixel::Color(0, 255, 0);
const uint32_t MAROON = Adafruit_NeoPixel::Color(128, 0, 0);
const uint32_t NAVY = Adafruit_NeoPixel::Color(0, 0, 128);
const uint32_t OLIVE = Adafruit_NeoPixel::Color(128, 128, 0);
const uint32_t ORANGE = Adafruit_NeoPixel::Color(255, 165, 0);
const uint32_t PINK = Adafruit_NeoPixel::Color(255, 192, 203);
const uint32_t PURPLE = Adafruit_NeoPixel::Color(128, 0, 128);
const uint32_t SILVER = Adafruit_NeoPixel::Color(192, 192, 192);
const uint32_t TEAL = Adafruit_NeoPixel::Color(0, 128, 128);
const uint32_t VIOLET = Adafruit_NeoPixel::Color(238, 130, 238);
const uint32_t LIGHT_RED = Adafruit_NeoPixel::Color(255, 102, 102);
const uint32_t DARK_RED = Adafruit_NeoPixel::Color(139, 0, 0);
const uint32_t LIGHT_GREEN = Adafruit_NeoPixel::Color(144, 238, 144);
const uint32_t DARK_GREEN = Adafruit_NeoPixel::Color(0, 100, 0);
const uint32_t LIGHT_BLUE = Adafruit_NeoPixel::Color(173, 216, 230);
const uint32_t DARK_BLUE = Adafruit_NeoPixel::Color(0, 0, 139);
const uint32_t LIGHT_YELLOW = Adafruit_NeoPixel::Color(255, 255, 224);
const uint32_t DARK_YELLOW = Adafruit_NeoPixel::Color(204, 204, 0);
const uint32_t AZURE = Adafruit_NeoPixel::Color(240, 255, 255);
const uint32_t CHARTREUSE = Adafruit_NeoPixel::Color(127, 255, 0);
const uint32_t CHOCOLATE = Adafruit_NeoPixel::Color(210, 105, 30);
const uint32_t CORNFLOWER_BLUE = Adafruit_NeoPixel::Color(100, 149, 237);
const uint32_t DARK_ORCHID = Adafruit_NeoPixel::Color(153, 50, 204);
const uint32_t FIREBRICK = Adafruit_NeoPixel::Color(178, 34, 34);
const uint32_t HOT_PINK = Adafruit_NeoPixel::Color(255, 105, 180);
const uint32_t MIDNIGHT_BLUE = Adafruit_NeoPixel::Color(25, 25, 112);
const uint32_t MINT_CREAM = Adafruit_NeoPixel::Color(245, 255, 250);
const uint32_t MISTY_ROSE = Adafruit_NeoPixel::Color(255, 228, 225);
const uint32_t NAVAJO_WHITE = Adafruit_NeoPixel::Color(255, 222, 173);
const uint32_t OLD_LACE = Adafruit_NeoPixel::Color(253, 245, 230);
const uint32_t PALE_TURQUOISE = Adafruit_NeoPixel::Color(175, 238, 238);
const uint32_t PEACH_PUFF = Adafruit_NeoPixel::Color(255, 218, 185);
const uint32_t ROYAL_BLUE = Adafruit_NeoPixel::Color(65, 105, 225);
const uint32_t SADDLE_BROWN = Adafruit_NeoPixel::Color(139, 69, 19);
const uint32_t SANDY_BROWN = Adafruit_NeoPixel::Color(244, 164, 96);
const uint32_t SEA_GREEN = Adafruit_NeoPixel::Color(46, 139, 87);
const uint32_t SKY_BLUE = Adafruit_NeoPixel::Color(135, 206, 235);
const uint32_t SLATE_BLUE = Adafruit_NeoPixel::Color(106, 90, 205);
const uint32_t SPRING_GREEN = Adafruit_NeoPixel::Color(0, 255, 127);
const uint32_t STEEL_BLUE = Adafruit_NeoPixel::Color(70, 130, 180);
const uint32_t TOMATO = Adafruit_NeoPixel::Color(255, 99, 71);
const uint32_t TURQUOISE = Adafruit_NeoPixel::Color(64, 224, 208);
const uint32_t WHEAT = Adafruit_NeoPixel::Color(245, 222, 179);

const uint32_t OFF = Adafruit_NeoPixel::Color(0, 0, 0);

Colors::Colors(){

const uint32_t colors[] = {
        RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, GRAY, AQUA,
        BEIGE, CORAL, CRIMSON, FUCHSIA, GOLD, INDIGO, IVORY, KHAKI, LAVENDER,
        LIME, MAROON, NAVY, OLIVE, ORANGE, PINK, PURPLE, SILVER, TEAL, VIOLET,
        LIGHT_RED, DARK_RED, LIGHT_GREEN, DARK_GREEN, LIGHT_BLUE, DARK_BLUE,
        LIGHT_YELLOW, DARK_YELLOW, AZURE, CHARTREUSE, CHOCOLATE, CORNFLOWER_BLUE,
        DARK_ORCHID, FIREBRICK, HOT_PINK, MIDNIGHT_BLUE, MINT_CREAM, MISTY_ROSE,
        NAVAJO_WHITE, OLD_LACE, PALE_TURQUOISE, PEACH_PUFF, ROYAL_BLUE,
        SADDLE_BROWN, SANDY_BROWN, SEA_GREEN, SKY_BLUE, SLATE_BLUE,
        SPRING_GREEN, STEEL_BLUE, TOMATO, TURQUOISE, WHEAT
      };

    for (int i = 0 ; i < 61 ; i++){
      ALLCOLORS[i] = colors[i];
    }

    const char* colorNames[] = {
        "RED", "GREEN", "BLUE", "YELLOW", "CYAN", "MAGENTA", "WHITE", "GRAY", "AQUA",
        "BEIGE", "CORAL", "CRIMSON", "FUCHSIA", "GOLD", "INDIGO", "IVORY", "KHAKI", "LAVENDER",
        "LIME", "MAROON", "NAVY", "OLIVE", "ORANGE", "PINK", "PURPLE", "SILVER", "TEAL", "VIOLET",
        "LIGHT_RED", "DARK_RED", "LIGHT_GREEN", "DARK_GREEN", "LIGHT_BLUE", "DARK_BLUE",
        "LIGHT_YELLOW", "DARK_YELLOW", "AZURE", "CHARTREUSE", "CHOCOLATE", "CORNFLOWER_BLUE",
        "DARK_ORCHID", "FIREBRICK", "HOT_PINK", "MIDNIGHT_BLUE", "MINT_CREAM", "MISTY_ROSE",
        "NAVAJO_WHITE", "OLD_LACE", "PALE_TURQUOISE", "PEACH_PUFF", "ROYAL_BLUE", "SADDLE_BROWN",
        "SANDY_BROWN", "SEA_GREEN", "SKY_BLUE", "SLATE_BLUE", "SPRING_GREEN", "STEEL_BLUE",
        "TOMATO", "TURQUOISE", "WHEAT"
    };

    for (int i = 0; i < 61; i++) {
        colorMappings[i].name = colorNames[i];
        colorMappings[i].color = ALLCOLORS[i];
    }
}

uint32_t Colors::getColorByName(const String& name) {
    const char* colorName = name.c_str(); 
    for (int i = 0; i < sizeof(colorMappings) / sizeof(colorMappings[0]); ++i) {
        // if (name == colorMappings[i].name) {
          if (strcmp(colorMappings[i].name, colorName) == 0) {
            return colorMappings[i].color;
        }
    }
    return 0; 
}


    // ALLCOLORS[0] = RED;
    // ALLCOLORS[1] = GREEN;
    // ALLCOLORS[2] = BLUE;
    // ALLCOLORS[3] = YELLOW;
    // ALLCOLORS[4] = CYAN;
    // ALLCOLORS[5] = MAGENTA;
    // ALLCOLORS[6] = WHITE;
    // ALLCOLORS[7] = GRAY;
    // ALLCOLORS[8] = AQUA;
    // ALLCOLORS[9] = BEIGE;
    // ALLCOLORS[10] = CORAL;
    // ALLCOLORS[11] = CRIMSON;
    // ALLCOLORS[12] = FUCHSIA;
    // ALLCOLORS[13] = GOLD;
    // ALLCOLORS[14] = INDIGO;
    // ALLCOLORS[15] = IVORY;
    // ALLCOLORS[16] = KHAKI;
    // ALLCOLORS[17] = LAVENDER;
    // ALLCOLORS[18] = LIME;
    // ALLCOLORS[19] = MAROON;
    // ALLCOLORS[20] = NAVY;
    // ALLCOLORS[21] = OLIVE;
    // ALLCOLORS[22] = ORANGE;
    // ALLCOLORS[23] = PINK;
    // ALLCOLORS[24] = PURPLE;
    // ALLCOLORS[25] = SILVER;
    // ALLCOLORS[26] = TEAL;
    // ALLCOLORS[27] = VIOLET;
    // ALLCOLORS[28] = LIGHT_RED;
    // ALLCOLORS[29] = DARK_RED;
    // ALLCOLORS[30] = LIGHT_GREEN;
    // ALLCOLORS[31] = DARK_GREEN;
    // ALLCOLORS[32] = LIGHT_BLUE;
    // ALLCOLORS[33] = DARK_BLUE;
    // ALLCOLORS[34] = LIGHT_YELLOW;
    // ALLCOLORS[35] = DARK_YELLOW;
    // ALLCOLORS[36] = AZURE;
    // ALLCOLORS[37] = CHARTREUSE;
    // ALLCOLORS[38] = CHOCOLATE;
    // ALLCOLORS[39] = CORNFLOWER_BLUE;
    // ALLCOLORS[40] = DARK_ORCHID;
    // ALLCOLORS[41] = FIREBRICK;
    // ALLCOLORS[42] = HOT_PINK;
    // ALLCOLORS[43] = MIDNIGHT_BLUE;
    // ALLCOLORS[44] = MINT_CREAM;
    // ALLCOLORS[45] = MISTY_ROSE;
    // ALLCOLORS[46] = NAVAJO_WHITE;
    // ALLCOLORS[47] = OLD_LACE;
    // ALLCOLORS[48] = PALE_TURQUOISE;
    // ALLCOLORS[49] = PEACH_PUFF;
    // ALLCOLORS[50] = ROYAL_BLUE;
    // ALLCOLORS[51] = SADDLE_BROWN;
    // ALLCOLORS[52] = SANDY_BROWN;
    // ALLCOLORS[53] = SEA_GREEN;
    // ALLCOLORS[54] = SKY_BLUE;
    // ALLCOLORS[55] = SLATE_BLUE;
    // ALLCOLORS[56] = SPRING_GREEN;
    // ALLCOLORS[57] = STEEL_BLUE;
    // ALLCOLORS[58] = TOMATO;
    // ALLCOLORS[59] = TURQUOISE;
    // ALLCOLORS[60] = WHEAT;

// const ColorMapping Colors::colorMappings[] = {
//     // RED
//     {"RED", RED},
//     {"LIGHT_RED", LIGHT_RED},
//     {"DARK_RED", DARK_RED},
//     {"TOMATO", TOMATO},
//     {"MAGENTA", MAGENTA},
//     {"INDIGO", INDIGO},
//     {"CRIMSON", CRIMSON},
//     {"MAROON", MAROON},
//     {"PURPLE", PURPLE},
//     {"FIREBRICK", FIREBRICK},

//     // GREEN
//     {"GREEN", GREEN},
//     {"LIGHT_GREEN", LIGHT_GREEN},
//     {"DARK_GREEN", DARK_GREEN},
//     {"SEA_GREEN", SEA_GREEN},
//     {"SPRING_GREEN", SPRING_GREEN},
//     {"AQUA", AQUA},
//     {"CYAN", CYAN},
//     {"MINT_CREAM", MINT_CREAM},
//     {"TURQUOISE", TURQUOISE},
//     {"OLIVE", OLIVE},
//     {"TEAL", TEAL},
//     {"LIME", LIME},
//     {"CHARTREUSE", CHARTREUSE},

//     // BLUE
//     {"BLUE", BLUE},
//     {"LIGHT_BLUE", LIGHT_BLUE},
//     {"DARK_BLUE", DARK_BLUE},
//     {"CORNFLOWER_BLUE", CORNFLOWER_BLUE},
//     {"MIDNIGHT_BLUE", MIDNIGHT_BLUE},
//     {"ROYAL_BLUE", ROYAL_BLUE},
//     {"SKY_BLUE", SKY_BLUE},
//     {"SLATE_BLUE", SLATE_BLUE},
//     {"STEEL_BLUE", STEEL_BLUE},
//     {"PALE_TURQUOISE", PALE_TURQUOISE},
//     {"FUCHSIA", FUCHSIA},
//     {"NAVY", NAVY},
//     {"DARK_ORCHID", DARK_ORCHID},

//     // YELLOW
//     {"YELLOW", YELLOW},
//     {"LIGHT_YELLOW", LIGHT_YELLOW},
//     {"DARK_YELLOW", DARK_YELLOW},
//     {"GOLD", GOLD},
//     {"ORANGE", ORANGE},

//     // BROWN
//     {"SADDLE_BROWN", SADDLE_BROWN},
//     {"SANDY_BROWN", SANDY_BROWN},
//     {"CHOCOLATE", CHOCOLATE},
//     {"KHAKI", KHAKI},

//     // WHITE
//     {"BEIGE", BEIGE},
//     {"IVORY", IVORY},
//     {"WHITE", WHITE},
//     {"NAVAJO_WHITE", NAVAJO_WHITE},
//     {"GRAY", GRAY},

//     //NIE DZIALA
//     {"HOT_PINK", HOT_PINK},
//     {"AZURE", AZURE},
//     {"WHEAT", WHEAT},
//     {"PINK", PINK},
//     {"PEACH_PUFF", PEACH_PUFF},
//     {"CORAL", CORAL},
//     {"SILVER", SILVER},
//     {"VIOLET", VIOLET},
//     {"LAVENDER", LAVENDER},
//     {"MISTY_ROSE", MISTY_ROSE},
//     {"OLD_LACE", OLD_LACE}

// const uint32_t Colors::ALLCOLORS[] = {
//         RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, GRAY, AQUA,
//         BEIGE, CORAL, CRIMSON, FUCHSIA, GOLD, INDIGO, IVORY, KHAKI, LAVENDER,
//         LIME, MAROON, NAVY, OLIVE, ORANGE, PINK, PURPLE, SILVER, TEAL, VIOLET,
//         LIGHT_RED, DARK_RED, LIGHT_GREEN, DARK_GREEN, LIGHT_BLUE, DARK_BLUE,
//         LIGHT_YELLOW, DARK_YELLOW, AZURE, CHARTREUSE, CHOCOLATE, CORNFLOWER_BLUE,
//         DARK_ORCHID, FIREBRICK, HOT_PINK, MIDNIGHT_BLUE, MINT_CREAM, MISTY_ROSE,
//         NAVAJO_WHITE, OLD_LACE, PALE_TURQUOISE, PEACH_PUFF, ROYAL_BLUE,
//         SADDLE_BROWN, SANDY_BROWN, SEA_GREEN, SKY_BLUE, SLATE_BLUE,
//         SPRING_GREEN, STEEL_BLUE, TOMATO, TURQUOISE, WHEAT
//     };