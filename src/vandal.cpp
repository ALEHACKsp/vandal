#include "vandal.hpp"

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
  Frame::Frame( const std::string & Name, const std::array<int, 4> & Bounds ) noexcept : Bounds( Bounds ) {
    using namespace Rendering;

    Render.Rectangle(
        Bounds[ 0 ], Bounds[ 1 ], Bounds[ 2 ], Bounds[ 3 ], Utilities::VColor( 22, 22, 22, 255 ), Rendering::ADDITIVE );
  }
  // --------------------------------------------------------

  // --------------------------------------------------------
  Widget::Widget( const std::string & Name, const std::array<int, 4> & Bounds ) noexcept : Bounds( Bounds ) {
    Frame( Name, Bounds );
  }
  // --------------------------------------------------------

  // --------------------------------------------------------
  UI::UI( const std::string & Name, const std::array<int, 4> & Bounds ) noexcept : Bounds( Bounds ) { Frame( Name, Bounds ); }
  // --------------------------------------------------------

  // --------------------------------------------------------
  IDirect3DDevice9 * Rendering::VRender::Device = nullptr;

  void Handling::Initialize( ) noexcept {
    // This only serves as an example, provided value to initialize is unrelated to Vandal
    if ( !Rendering::Render.Device )
      Rendering::Render.Device = Utils::g_Context.g_pDevice;

    Rendering::Render.SetupDeviceStates( );
    Rendering::Render.SetupFonts( );
  }

  void Handling::Release( ) noexcept {
    Rendering::Render.Device = nullptr;

    Rendering::Render.ReleaseFonts( );
  }
  // --------------------------------------------------------
} // namespace Vandal
