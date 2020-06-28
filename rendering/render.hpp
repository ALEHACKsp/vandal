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
      struct VVertex {
        float X, Y, Z, RHW;
        D3DCOLOR Color;
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