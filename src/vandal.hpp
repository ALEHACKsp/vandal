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
//     ____   ____                  .___      .__		  |
//     \   \ /   /____    ____    __| _/____  |  |		  |
//      \   Y   /\__  \  /    \  / __ |\__  \ |  |		  |
//       \     /  / __ \|   |  \/ /_/ | / __ \|  |__	  |
//        \___/  (____  /___|  /\____ |(____  /____/      |
//                    \/     \/      \/     \/			  |
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
  class Frame {
  private:
    std::array<int, 4> Bounds{ };

  public:
    // --------------------------------------------------------
    /// <summary>
    /// Create Form
    /// </summary>
    /// <param name="Name">Form Name</param>
    /// <param name="Bounds">Form Bounds</param>
    Frame( const std::string & Name, const std::array<int, 4> & Bounds ) noexcept;
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
    std::array<int, 4> Bounds{ };

  public:
    // --------------------------------------------------------
    /// <summary>
    /// Initialize Widget form
    /// </summary>
    /// <param name="Name">Form Name</param>
    /// <param name="Bounds">Form Bounds</param>
    Widget( const std::string & Name, const std::array<int, 4> & Bounds ) noexcept;
    // --------------------------------------------------------

    // --------------------------------------------------------
    /// <summary>
    /// Get Menu Position from passing
    /// </summary>
    /// <returns></returns>
    constexpr std::pair<int, int> GetPosition( ) noexcept { return std::make_pair( Bounds[ 0 ], Bounds[ 1 ] ); }
    constexpr std::pair<int, int> GetSize( ) noexcept { return std::make_pair( Bounds[ 2 ], Bounds[ 3 ] ); }
    // --------------------------------------------------------
  };
  // --------------------------------------------------------

  // --------------------------------------------------------
  class UI {
  private:
    std::array<int, 4> Bounds{ };

  public:
    // --------------------------------------------------------
    /// <summary>
    /// Initialize UI form
    /// </summary>
    /// <param name="Name">Form Name (passed to form constructor)</param>
    /// <param name="Bounds">Form Bounds (passed to form constructor)</param>
    UI( const std::string & Name, const std::array<int, 4> & Bounds ) noexcept;
    // --------------------------------------------------------

    // --------------------------------------------------------
    constexpr std::pair<int, int> GetPosition( ) noexcept { return std::make_pair( Bounds[ 0 ], Bounds[ 1 ] ); }
    constexpr std::pair<int, int> GetSize( ) noexcept { return std::make_pair( Bounds[ 2 ], Bounds[ 3 ] ); }
    // --------------------------------------------------------
  };
  // --------------------------------------------------------
} // namespace Vandal
