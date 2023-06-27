#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"
#include "bn_sprite_items_variable_8x16_font.h"

namespace pvz {
    constexpr bn::utf8_character variable_8x16_font_utf8_characters[] = {
        "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿"
    };

    constexpr int8_t variable_8x16_sprite_font_character_widths[] = {
        6,  // 32
        4,  // 33 !
        7,  // 34 "
        8,  // 35 #
        8,  // 36 $
        7,  // 37 %
        8,  // 38 &
        4,  // 39 '
        5,  // 40 (
        5,  // 41 )
        7,  // 42 *
        7,  // 43 +
        4,  // 44 ,
        7,  // 45 -
        4,  // 46 .
        7,  // 47 /
        7,  // 48 0
        4,  // 49 1
        7,  // 50 2
        7,  // 51 3
        8,  // 52 4
        7,  // 53 5
        7,  // 54 6
        7,  // 55 7
        7,  // 56 8
        7,  // 57 9
        4,  // 58 :
        4,  // 59 ;
        6,  // 60 <
        7,  // 61 =
        6,  // 62 >
        7,  // 63 ?
        8,  // 64 @
        7,  // 65 A
        7,  // 66 B
        6,  // 67 C
        8,  // 68 D
        7,  // 69 E
        7,  // 70 F
        7,  // 71 G
        8,  // 72 H
        4,  // 73 I
        6,  // 74 J
        7,  // 75 K
        6,  // 76 L
        8,  // 77 M
        7,  // 78 N
        7,  // 79 O
        7,  // 80 P
        7,  // 81 Q
        7,  // 82 R
        6,  // 83 S
        8,  // 84 T
        7,  // 85 U
        8,  // 86 V
        8,  // 87 W
        8,  // 88 X
        8,  // 89 Y
        7,  // 90 Z
        5,  // 91 [
        7,  // 92
        5,  // 93 ]
        4,  // 94 ^
        7,  // 95 _
        4,  // 96 `
        6,  // 97 a
        6,  // 98 b
        6,  // 99 c
        7,  // 100 d
        6,  // 101 e
        5,  // 102 f
        7,  // 103 g
        7,  // 104 h
        3,  // 105 i
        5,  // 106 j
        7,  // 107 k
        4,  // 108 l
        8,  // 109 m
        7,  // 110 n
        6,  // 111 o
        7,  // 112 p
        6,  // 113 q
        5,  // 114 r
        6,  // 115 s
        6,  // 116 t
        7,  // 117 u
        8,  // 118 v
        8,  // 119 w
        8,  // 120 x
        8,  // 121 y
        6,  // 122 z
        6,  // 123 {
        3,  // 124 |
        6,  // 125 }
        8,  // 126 ~
        7,  // Á
        6,  // É
        7,  // Í
        7,  // Ó
        7,  // Ú
        7,  // Ü
        7,  // Ñ
        5,  // á
        5,  // é
        5,  // í
        5,  // ó
        6,  // ú
        6,  // ü
        5,  // ñ
        3,  // ¡
        7,  // ¿
    };

    constexpr bn::span<const bn::utf8_character> variable_8x16_font_utf8_characters_span(
        variable_8x16_font_utf8_characters
    );

    constexpr auto variable_8x16_font_utf8_characters_map =
        bn::utf8_characters_map<variable_8x16_font_utf8_characters_span>();

    constexpr bn::sprite_font variable_8x16_font(
        bn::sprite_items::variable_8x16_font, variable_8x16_font_utf8_characters_map.reference(), variable_8x16_sprite_font_character_widths
    );
}

int main()
{
    bn::core::init();

    bn::sprite_text_generator white_text_generator(pvz::variable_8x16_font);

    bn::vector<bn::sprite_ptr, 32> text_sprites;
    white_text_generator.generate(-85, -60, "THE QUICK BROWN FOX JUMPS", text_sprites);
    white_text_generator.generate(-55, -44, "OVER THE LAZY DOG", text_sprites);

    white_text_generator.generate(-72, -24, "the quick brown fox jumps", text_sprites);
    white_text_generator.generate(-42, -8, "over the lazy dog", text_sprites);

    white_text_generator.generate(-72, 16, "A HUGE WAVE OF ZOMBIES", text_sprites);
    white_text_generator.generate(-42, 32, "IS APPROACHING", text_sprites);
    
    white_text_generator.generate(-30, 48, "0123456789", text_sprites);

    while(true)
    {
        bn::core::update();
    }
}
