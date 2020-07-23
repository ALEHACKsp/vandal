// --------------------------------------------------------
#include "vandal.hpp"
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
  Frame::Frame( const std::string & Name,
                const std::array<int, 4> & Bounds,
                const Styling & Style,
                const int BorderType,
                const int OutlineType ) noexcept
      : Name( Name ), Bounds( Bounds ) {
    using namespace Rendering;

    // Form (Fill)
    Render.Rectangle( Bounds[ 0 ], Bounds[ 1 ], Bounds[ 2 ], Bounds[ 3 ], Style.MainFormColor, Rendering::ADDITIVE );

    switch ( OutlineType ) {
      case Rendering::OutlineTypes::ONONE:
        break;
      case Rendering::OutlineTypes::INNER:
        Render.RectangleOutline(
            Bounds[ 0 ], Bounds[ 1 ], Bounds[ 2 ], Bounds[ 3 ], Style.MainFormOutlineColor, Rendering::ADDITIVE );
        break;
      case Rendering::OutlineTypes::OUTER:
        switch ( BorderType ) {
          case Rendering::BorderTypes::BNONE:
            Render.RectangleOutline( Bounds[ 0 ] - 1,
                                     Bounds[ 1 ] - 1,
                                     Bounds[ 2 ] + 2,
                                     Bounds[ 3 ] + 2,
                                     Style.MainFormOutlineColor,
                                     Rendering::ADDITIVE );
            break;
          case Rendering::BorderTypes::SMALL:
            Render.RectangleOutline( Bounds[ 0 ] - 2,
                                     Bounds[ 1 ] - 2,
                                     Bounds[ 2 ] + 4,
                                     Bounds[ 3 ] + 4,
                                     Style.MainFormOutlineColor,
                                     Rendering::ADDITIVE );
            break;
          case Rendering::BorderTypes::THICK:
            Render.RectangleOutline( Bounds[ 0 ] - 5,
                                     Bounds[ 1 ] - 5,
                                     Bounds[ 2 ] + 10,
                                     Bounds[ 3 ] + 10,
                                     Style.MainFormOutlineColor,
                                     Rendering::ADDITIVE );
            break;
        }
        break;
    }

    // Form Border (Outline)
    switch ( BorderType ) {
      case Rendering::BorderTypes::BNONE:
        break;
      case Rendering::BorderTypes::SMALL:
        Render.RectangleOutline(
            Bounds[ 0 ] - 1, Bounds[ 1 ] - 1, Bounds[ 2 ] + 2, Bounds[ 3 ] + 2, Style.BorderColor[ 0 ], Rendering::ADDITIVE );
        break;
      case Rendering::BorderTypes::THICK:
        Render.RectangleOutline(
            Bounds[ 0 ] - 1, Bounds[ 1 ] - 1, Bounds[ 2 ] + 2, Bounds[ 3 ] + 2, Style.BorderColor[ 0 ], Rendering::ADDITIVE );
        Render.RectangleOutline(
            Bounds[ 0 ] - 2, Bounds[ 1 ] - 2, Bounds[ 2 ] + 4, Bounds[ 3 ] + 4, Style.BorderColor[ 1 ], Rendering::ADDITIVE );
        Render.RectangleOutline(
            Bounds[ 0 ] - 3, Bounds[ 1 ] - 3, Bounds[ 2 ] + 6, Bounds[ 3 ] + 6, Style.BorderColor[ 2 ], Rendering::ADDITIVE );
        Render.RectangleOutline(
            Bounds[ 0 ] - 4, Bounds[ 1 ] - 4, Bounds[ 2 ] + 8, Bounds[ 3 ] + 8, Style.BorderColor[ 3 ], Rendering::ADDITIVE );
        break;
    }
  } // namespace Vandal
  // --------------------------------------------------------

  // --------------------------------------------------------
  Widget::Widget( const std::string & Name,
                  const std::array<int, 4> &Bounds,
                  const Styling & Style,
                  const int BorderType,
                  const int OutlineType ) noexcept
      : Name( Name ), Bounds( Bounds ) {
    Frame( Name, Bounds, Style, BorderType, OutlineType );
  }
  // --------------------------------------------------------

  // --------------------------------------------------------
  UI::UI( const std::string & Name,
          const std::array<int, 4> & Bounds,
          const Styling & Style,
          const int BorderType,
          const int OutlineType ) noexcept
      : Name( Name ), Bounds( Bounds ) {
    Frame( Name, Bounds, Style, BorderType, OutlineType );
  }
  // --------------------------------------------------------

  // --------------------------------------------------------
  // Device is a static variable, thus we will initialize it first, just in case, to not encounter any issue
  IDirect3DDevice9 * Rendering::VRender::Device = nullptr;

  void Handling::Initialize( IDirect3DDevice9 * Device ) noexcept {
    // This only serves as an example, provided value to initialize is unrelated to Vandal
    // First, initialize rendering device
    if ( !Rendering::Render.Device )
      Rendering::Render.Device = Device;

    // Then, proceed to call other functions dependant of the device
    Rendering::Render.SetupDeviceStates( );
    Rendering::Render.SetupFonts( );
  }

  void Handling::Release( ) noexcept {
    // First, get rid of functions that may depend on the device
    Rendering::Render.ReleaseFonts( );

    // Then, get rid of the device itself
    Rendering::Render.Device = nullptr;
  }
  // --------------------------------------------------------
} // namespace Vandal
