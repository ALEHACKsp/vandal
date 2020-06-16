// --------------------------------------------------------
#include "render.hpp"
// --------------------------------------------------------

// --------------------------------------------------------
#ifdef _WIN32
// TODO: Get rid of this
// CAUSE: Vertex must be a float to work with DX9, but we don't exactly want float values, do we?
#pragma warning( disable : 4244 )
#pragma warning( disable : 4838 )
#endif
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
  namespace Rendering {
    // --------------------------------------------------------
    void VRender::Rectangle( const int X,
                             const int Y,
                             const int W,
                             const int H,
                             const Utilities::VColor & VColor,
                             const bool AdditiveVertex ) noexcept {
      const D3DCOLOR Color = D3DCOLOR_RGBA( VColor.Red, VColor.Blue, VColor.Green, VColor.Alpha );

      const VRender::VVertex Vertices[ 4 ] = {
        { X, AdditiveVertex ? Y + H : H, 0.f, 1.f, Color },
        { X, Y, 0.f, 1.f, Color },
        { AdditiveVertex ? X + W : W, AdditiveVertex ? Y + H : H, 0.f, 1.f, Color },
        { AdditiveVertex ? X + W : W, Y, 0.f, 1.f, Color },
      };

      Device->SetFVF( D3DFVF_XYZRHW | D3DFVF_DIFFUSE );
      Device->DrawPrimitiveUP( D3DPT_TRIANGLESTRIP, 2, Vertices, sizeof( VRender::VVertex ) );
    }
    // --------------------------------------------------------

    // --------------------------------------------------------
    void VRender::SetupDeviceStates( ) noexcept {
      Device->SetRenderState( D3DRS_LIGHTING, FALSE );
      Device->SetRenderState( D3DRS_FOGENABLE, FALSE );
      Device->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
      Device->SetRenderState( D3DRS_FILLMODE, D3DFILL_SOLID );

      Device->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
      Device->SetRenderState( D3DRS_SCISSORTESTENABLE, TRUE );
      Device->SetRenderState( D3DRS_ZWRITEENABLE, FALSE );
      Device->SetRenderState( D3DRS_STENCILENABLE, FALSE );

      Device->SetRenderState( D3DRS_MULTISAMPLEANTIALIAS, TRUE );
      Device->SetRenderState( D3DRS_ANTIALIASEDLINEENABLE, TRUE );

      Device->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
      Device->SetRenderState( D3DRS_ALPHATESTENABLE, FALSE );
      Device->SetRenderState( D3DRS_SEPARATEALPHABLENDENABLE, TRUE );
      Device->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
      Device->SetRenderState( D3DRS_SRCBLENDALPHA, D3DBLEND_INVDESTALPHA );
      Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
      Device->SetRenderState( D3DRS_DESTBLENDALPHA, D3DBLEND_ONE );

      Device->SetRenderState( D3DRS_SRGBWRITEENABLE, FALSE );
      Device->SetRenderState( D3DRS_COLORWRITEENABLE,
                              D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN | D3DCOLORWRITEENABLE_BLUE |
                                  D3DCOLORWRITEENABLE_ALPHA );
    }
    // --------------------------------------------------------

    // --------------------------------------------------------
    void VRender::SetupFonts( ) noexcept {}
    // --------------------------------------------------------

    // --------------------------------------------------------
    void VRender::ReleaseFonts( ) noexcept {}
    // --------------------------------------------------------
  } // namespace Rendering
} // namespace Vandal