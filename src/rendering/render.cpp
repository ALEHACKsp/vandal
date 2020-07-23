// --------------------------------------------------------
#include "render.hpp"
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
      const D3DCOLOR Color = D3DCOLOR_RGBA( VColor.Red, VColor.Green, VColor.Blue, VColor.Alpha );

      const std::array<VRender::VVertex, 4> Vertices = {
        VRender::VVertex( X, AdditiveVertex ? Y + H : H, 0.f, 1.f, Color ),
        VRender::VVertex( X, Y, 0.f, 1.f, Color ),
        VRender::VVertex( AdditiveVertex ? X + W : W, AdditiveVertex ? Y + H : H, 0.f, 1.f, Color ),
        VRender::VVertex( AdditiveVertex ? X + W : W, Y, 0.f, 1.f, Color )
      };

      Device->SetFVF( D3DFVF_XYZRHW | D3DFVF_DIFFUSE );
      Device->DrawPrimitiveUP( D3DPT_TRIANGLESTRIP, 2, &Vertices, sizeof( VRender::VVertex ) );
    }

    void VRender::RectangleOutline( const int X,
                                    const int Y,
                                    const int W,
                                    const int H,
                                    const Utilities::VColor & Color,
                                    const bool AdditiveVertex ) noexcept {
      Rectangle( X, Y, W, 1, Color, AdditiveVertex );
      Rectangle( X, Y, 1, H, Color, AdditiveVertex );
      Rectangle( X + W - 1, Y, 1, H, Color, AdditiveVertex );
      Rectangle( X, Y + H - 1, W, 1, Color, AdditiveVertex );
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