#pragma once

// --------------------------------------------------------
#include <inttypes.h>
// --------------------------------------------------------

// Vandal Framework -- Vandal Framework -- Vandal Framework
//     ____   ____                  .___      .__
//     \   \ /   /____    ____    __| _/____  |  |
//      \   Y   /\__  \  /    \  / __ |\__  \ |  |
//       \     /  / __ \|   |  \/ /_/ | / __ \|  |__
//        \___/  (____  /___|  /\____ |(____  /____/
//                    \/     \/      \/     \/
// Vandal Framework -- Vandal Framework -- Vandal Framework

namespace Vandal {
  namespace Utilities {
    class VColor {
    public:
      uint8_t Red, Green, Blue, Alpha;

    public:
      // --------------------------------------------------------
      constexpr VColor( ) noexcept : Red( 0 ), Green( 0 ), Blue( 0 ), Alpha( 0 ) {}
      // --------------------------------------------------------

      // --------------------------------------------------------
      constexpr VColor( const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a ) noexcept
          : Red( r ), Green( g ), Blue( b ), Alpha( a ) {}
      // --------------------------------------------------------

      // --------------------------------------------------------
      constexpr VColor( const uint8_t r, const uint8_t g, const uint8_t b ) noexcept
          : Red( r ), Green( g ), Blue( b ), Alpha( 255 ) {}
      // --------------------------------------------------------

      // --------------------------------------------------------
      constexpr VColor( VColor & color ) noexcept
          : Red( color.Red ), Green( color.Green ), Blue( color.Blue ), Alpha( color.Alpha ) {}
      // --------------------------------------------------------
    };
  } // namespace Utilities
} // namespace Vandal