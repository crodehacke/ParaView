/*=========================================================================

  Program:   ParaView
  Module:    vtkPVGenericRenderWindowInteractor.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2000-2001 Kitware Inc. 469 Clifton Corporate Parkway,
Clifton Park, NY, 12065, USA.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither the name of Kitware nor the names of any contributors may be used
   to endorse or promote products derived from this software without specific 
   prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
// .NAME vtkPVGenericRenderWindowInteractor
// .SECTION Description

#ifndef __vtkPVGenericRenderWindowInteractor_h
#define __vtkPVGenericRenderWindowInteractor_h

#include "vtkGenericRenderWindowInteractor.h"

class vtkPVRenderView;

class VTK_EXPORT vtkPVGenericRenderWindowInteractor : public vtkGenericRenderWindowInteractor
{
public:
  static vtkPVGenericRenderWindowInteractor *New();
  vtkTypeRevisionMacro(vtkPVGenericRenderWindowInteractor, vtkGenericRenderWindowInteractor);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  void SetPVRenderView(vtkPVRenderView *view);
  vtkGetObjectMacro(PVRenderView, vtkPVRenderView);

  // Description:
  // Set the event onformation, but remember keys from before.
  void SetMoveEventInformationFlipY(int x, int y);


  // Description:
  // 3D widgets call render on this interactor directly.
  // They call SetInteractive to tell whether to use still or interactive rendering.
  // This class just forwards the render request to ParaView's RenderModule.
  // DesiredUpdateRate is ignored.
  vtkSetMacro(InteractiveRenderEnabled,int);
  vtkGetMacro(InteractiveRenderEnabled,int);
  vtkBooleanMacro(InteractiveRenderEnabled,int);
  virtual void Render();

  // Description:
  // Methods broadcasted to the satellites to synchronize 3D widgets.
  void SatelliteLeftPress(float x, float y, float z, int control, int shift);
  void SatelliteMiddlePress(float x, float y, float z, int control, int shift);
  void SatelliteRightPress(float x, float y, float z, int control, int shift);
  void SatelliteLeftRelease(float x, float y, float z, int control, int shift);
  void SatelliteMiddleRelease(float x, float y, float z, int control, int shift);
  void SatelliteRightRelease(float x, float y, float z, int control, int shift);
  void SatelliteMove(float x, float y, float z);

protected:
  vtkPVGenericRenderWindowInteractor();
  ~vtkPVGenericRenderWindowInteractor();

  int CalculateReductionFactor(int winSize1, int renSize1);
  void PrepareForEvent(float wx, float wy, float wz, float xy[3],
    int* reductionFactor, int* renSize);
  
  vtkPVRenderView *PVRenderView;
  int ReductionFactor;
  int InteractiveRenderEnabled;

private:
  vtkPVGenericRenderWindowInteractor(const vtkPVGenericRenderWindowInteractor&); // Not implemented
  void operator=(const vtkPVGenericRenderWindowInteractor&); // Not implemented
};

#endif
