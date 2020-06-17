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
  Frame::Frame( std::string Name, std::array<int, 4> Bounds, const Styling Style, const int BorderType ) noexcept
      : Name( std::move( Name ) ), Bounds( std::move( Bounds ) ) {
    using namespace Rendering;

    // Form (Fill)
    Render.Rectangle(
        Bounds[ 0 ], Bounds[ 1 ], Bounds[ 2 ], Bounds[ 3 ], Style.MainFormColor, Rendering::ADDITIVE );

    // Form Border (Outline)
    switch ( BorderType ) {
      case Rendering::NONE:
        break;
      case Rendering::SMALL:
        Render.RectangleOutline(
            Bounds[ 0 ] - 1, Bounds[ 1 ] - 1, Bounds[ 2 ] + 2, Bounds[ 3 ] + 2, Style.BorderColor[ 0 ], Rendering::ADDITIVE );
        break;
      case Rendering::THICK:
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
  }
  // --------------------------------------------------------

  // --------------------------------------------------------
  Widget::Widget( std::string Name, std::array<int, 4> Bounds, Styling Style, const int BorderType ) noexcept
      : Name( std::move( Name ) ), Bounds( std::move( Bounds ) ) {
    Frame( Name, Bounds, Style, BorderType );
  }
  // --------------------------------------------------------

  // --------------------------------------------------------
  UI::UI( std::string Name, std::array<int, 4> Bounds, Styling Style, const int BorderType ) noexcept
      : Name( std::move( Name ) ), Bounds( std::move( Bounds ) ) {
    Frame( Name, Bounds, Style, BorderType );
  }
  // --------------------------------------------------------

  // --------------------------------------------------------
  // Device is a static variable, thus we will initialize it first, just in case, to not encounter any issue
  IDirect3DDevice9 * Rendering::VRender::Device = nullptr;

  void Handling::Initialize( ) noexcept {
    // This only serves as an example, provided value to initialize is unrelated to Vandal
    // First, initialize rendering device
    if ( !Rendering::Render.Device )
      Rendering::Render.Device = Utils::g_Context.g_pDevice;

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
