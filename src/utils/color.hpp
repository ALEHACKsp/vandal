#pragma once

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
      unsigned char Red, Green, Blue, Alpha;

    public:
      // --------------------------------------------------------
      constexpr VColor( const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a ) noexcept
          : Red( r ), Green( g ), Blue( b ), Alpha( a ) {}
      // --------------------------------------------------------

      // --------------------------------------------------------
      constexpr VColor( const unsigned char r, const unsigned char g, const unsigned char b ) noexcept
          : Red( r ), Green( g ), Blue( b ), Alpha( 255 ) {}
      // --------------------------------------------------------
    };
  } // namespace Utilities
} // namespace Vandal