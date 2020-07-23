#pragma once

// --------------------------------------------------------
#include "../utils/color.hpp"
// --------------------------------------------------------
#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>
// --------------------------------------------------------
#include <array>
// --------------------------------------------------------

// --------------------------------------------------------
/// <summary>
/// This is for the "loss of data" pass for the Vertex constructor, there is no loss of data whatsoever,
/// but for now we will need this hack.
/// </summary>
#pragma warning( disable : 4244 )
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
    // Enum for additive vertex checks
    enum { NOT_ADDITIVE = 0, ADDITIVE = 1 };
    // --------------------------------------------------------
    // Enum for form border
    enum BorderTypes { BNONE = 0, SMALL = 1, THICK = 2 };
    // --------------------------------------------------------
    // Enum for form outline
    enum OutlineTypes { ONONE = 0, INNER = 1, OUTER = 2 };
    // --------------------------------------------------------

    class VRender {
    public:
      static IDirect3DDevice9 * Device;

    public:
      // --------------------------------------------------------
      class VVertex {
      private:
        float X, Y, Z, RHW;
        D3DCOLOR Color;

      public:
        VVertex( const float X, const float Y, const int Z, const int RHW, const D3DCOLOR & Color )
            : X( X ), Y( Y ), Z( Z ), RHW( RHW ), Color( Color ) {}
        VVertex( const float X, const float Y, const float Z, const float RHW, const D3DCOLOR & Color )
            : X( X ), Y( Y ), Z( Z ), RHW( RHW ), Color( Color ) {}
        VVertex( const int X, const int Y, const float Z, const int RHW, const D3DCOLOR & Color )
            : X( X ), Y( Y ), Z( Z ), RHW( RHW ), Color( Color ) {}
        VVertex( const int X, const int Y, const float Z, const float RHW, const D3DCOLOR & Color )
            : X( X ), Y( Y ), Z( Z ), RHW( RHW ), Color( Color ) {}
      };
      // --------------------------------------------------------

    public:
      // --------------------------------------------------------
      /// <summary>
      /// Render Filled Rectangles
      /// </summary>
      /// <param name="X">X-axis position</param>
      /// <param name="Y">Y-axis position</param>
      /// <param name="W">Rectangle Width</param>
      /// <param name="H">Rectangle Height</param>
      /// <param name="Color">Rectangle Color</param>
      /// <param name="AdditiveVertex">Additive values for Vertex calculation</param>
      static void Rectangle( const int X,
                             const int Y,
                             const int W,
                             const int H,
                             const Utilities::VColor & Color,
                             const bool AdditiveVertex ) noexcept;

      /// <summary>
      /// Render Rectangle Outline
      /// </summary>
      /// <param name="X">X-axis position</param>
      /// <param name="Y">Y-axis position</param>
      /// <param name="W">Rectangle Width</param>
      /// <param name="H">Rectangle Height</param>
      /// <param name="Color">Rectangle Color</param>
      /// <param name="AdditiveVertex">Additive values for Vertex calculation</param>
      static void RectangleOutline( const int X,
                                    const int Y,
                                    const int W,
                                    const int H,
                                    const Utilities::VColor & Color,
                                    const bool AdditiveVertex ) noexcept;
      // --------------------------------------------------------

      // --------------------------------------------------------
      /// <summary>
      /// Settings for the D3D Render Engine to enhance rendering quality
      /// </summary>
      static void SetupDeviceStates( ) noexcept;

      /// <summary>
      /// Initialize Render Engine fonts
      /// </summary>
      static void SetupFonts( ) noexcept;
      // --------------------------------------------------------

      // --------------------------------------------------------
      /// <summary>
      /// Release Render Engine fonts
      /// </summary>
      static void ReleaseFonts( ) noexcept;
      // --------------------------------------------------------
    } inline Render{ };
  } // namespace Rendering
} // namespace Vandal