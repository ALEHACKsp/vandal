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
      constexpr VColor( ) noexcept : Red( 0 ), Green( 0 ), Blue( 0 ), Alpha( 0 ) {}
      // --------------------------------------------------------

      // --------------------------------------------------------
      constexpr VColor( const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a ) noexcept
          : Red( r ), Green( g ), Blue( b ), Alpha( a ) {}
      // --------------------------------------------------------

      // --------------------------------------------------------
      constexpr VColor( const unsigned char r, const unsigned char g, const unsigned char b ) noexcept
          : Red( r ), Green( g ), Blue( b ), Alpha( 255 ) {}
      // --------------------------------------------------------

      // --------------------------------------------------------
      constexpr VColor( VColor & color ) noexcept
          : Red( color.Red ), Green( color.Green ), Blue( color.Blue ), Alpha( color.Alpha ) {}
      // --------------------------------------------------------
    };
  } // namespace Utilities
} // namespace Vandal