#pragma once

// --------------------------------------------------------
#include "rendering/render.hpp"
#include "utils/color.hpp"
// --------------------------------------------------------
#include <array>
#include <math.h>
// --------------------------------------------------------
#include <memory>
#include <xmemory>
// --------------------------------------------------------
#include <string>
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
  // --------------------------------------------------------
  namespace Rendering {
    class VRender;
  } // namespace Rendering
  // --------------------------------------------------------

  // --------------------------------------------------------
  namespace Utilities {
    class VColor;
    class VVec2;
    class VVec3;
  } // namespace Utilities
  // --------------------------------------------------------

  // --------------------------------------------------------
  class Handling {
  private:
  public:
    // --------------------------------------------------------
    /// <summary>
    /// Initializes render engine
    /// </summary>
    static void Initialize( ) noexcept;

    /// <summary>
    /// Disposes render engine
    /// </summary>
    static void Release( ) noexcept;
    // --------------------------------------------------------
  } inline Handler{ };
  // --------------------------------------------------------

  // --------------------------------------------------------
  class Styling {
  public:
    constexpr Styling( ) noexcept {
      MainFormColor = Utilities::VColor( 22, 22, 22, 255 );
      BorderColor[ 0 ] = Utilities::VColor( 32, 32, 32, 255 );
      BorderColor[ 1 ] = Utilities::VColor( 48, 48, 48, 255 );
      BorderColor[ 2 ] = Utilities::VColor( 48, 48, 48, 255 );
      BorderColor[ 3 ] = Utilities::VColor( 32, 32, 32, 255 );
      MainFormOutlineColor = Utilities::VColor( 0, 0, 0, 245 );
    };

    Utilities::VColor MainFormColor{ };
    std::array<Utilities::VColor, 4> BorderColor{ };
    Utilities::VColor MainFormOutlineColor{ };
  };
  // --------------------------------------------------------

  // --------------------------------------------------------
  class Frame {
  private:
    std::string Name{ };
    std::array<int, 4> Bounds{ };

  public:
    // --------------------------------------------------------
    /// <summary>
    /// Create Form
    /// </summary>
    /// <param name="Name">Form Name</param>
    /// <param name="Bounds">Form Bounds</param>
    /// <param name="Style">Form Style</param>
    /// <param name="BorderType">Form Border Type</param>
    Frame( std::string Name,
           std::array<int, 4> Bounds,
           const Styling Style,
           const int BorderType,
           const int OutlineType ) noexcept;
    // --------------------------------------------------------

    // --------------------------------------------------------
    constexpr std::pair<int, int> GetPosition( ) noexcept { return std::make_pair( Bounds[ 0 ], Bounds[ 1 ] ); }
    constexpr std::pair<int, int> GetSize( ) noexcept { return std::make_pair( Bounds[ 2 ], Bounds[ 3 ] ); }
    // --------------------------------------------------------
  };
  // --------------------------------------------------------

  // --------------------------------------------------------
  class Widget {
  private:
    std::string Name{ };
    std::array<int, 4> Bounds{ };

  public:
    // --------------------------------------------------------
    /// <summary>
    /// Initialize Widget form
    /// </summary>
    /// <param name="Name">Form Name</param>
    /// <param name="Bounds">Form Bounds</param>
    /// <param name="Style">Form Style</param>
    /// <param name="BorderType">Form Border Type</param>
    Widget( std::string Name,
            std::array<int, 4> Bounds,
            const Styling Style,
            const int BorderType,
            const int OutlineType ) noexcept;
    // --------------------------------------------------------

    // --------------------------------------------------------
    constexpr std::pair<int, int> GetPosition( ) noexcept { return std::make_pair( Bounds[ 0 ], Bounds[ 1 ] ); }
    constexpr std::pair<int, int> GetSize( ) noexcept { return std::make_pair( Bounds[ 2 ], Bounds[ 3 ] ); }
    // --------------------------------------------------------
  };
  // --------------------------------------------------------

  // --------------------------------------------------------
  class UI {
  private:
    std::string Name{ };
    std::array<int, 4> Bounds{ };

  public:
    // --------------------------------------------------------
    /// <summary>
    /// Initialize UI form
    /// </summary>
    /// <param name="Name">Form Name</param>
    /// <param name="Bounds">Form Bounds</param>
    /// <param name="Style">Form Style</param>
    /// <param name="BorderType">Form Border Type</param>
    UI( std::string Name, std::array<int, 4> Bounds, const Styling Style, const int BorderType, const int OutlineType ) noexcept;
    // --------------------------------------------------------

    // --------------------------------------------------------
    constexpr std::pair<int, int> GetPosition( ) noexcept { return std::make_pair( Bounds[ 0 ], Bounds[ 1 ] ); }
    constexpr std::pair<int, int> GetSize( ) noexcept { return std::make_pair( Bounds[ 2 ], Bounds[ 3 ] ); }
    // --------------------------------------------------------
  };
  // --------------------------------------------------------
} // namespace Vandal