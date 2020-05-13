/*   ColDet - C++ 3D Collision Detection Library
 *   Copyright (C) 2000   Amir Geva
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 * 
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA  02111-1307, USA.
 *
 * Any comments, questions and bug reports send to:
 *   photon@photoneffect.com
 *
 * Or visit the home page: http://photoneffect.com/coldet/
 */
#include "sysdep.h"
#include "coldetimpl.h"

__CD__BEGIN

EXPORT CollisionModel3D* newCollisionModel3D(bool Static)
{
  return new CollisionModel3DImpl(Static);
}

CollisionModel3DImpl::CollisionModel3DImpl(bool Static)
: m_Root(Vector3D::Zero, Vector3D::Zero,0),
  m_Transform(Matrix3D::Identity),
  m_InvTransform(Matrix3D::Identity),
  m_ColTri1(Vector3D::Zero,Vector3D::Zero,Vector3D::Zero),
  m_ColTri2(Vector3D::Zero,Vector3D::Zero,Vector3D::Zero),
  m_iColTri1(0),
  m_iColTri2(0),
  m_Final(false),
  m_Static(Static)
{}

void CollisionModel3DImpl::addTriangle(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3)
{
  if (m_Final) Inconsistency::error();
  m_Triangles.push_back(BoxedTriangle(v1,v2,v3));
}

void CollisionModel3DImpl::addQuad(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3, const Vector3D& v4, Vector3D* arrayVecT1, Vector3D* arrayVecT2)
{
  if (arrayVecT1 != NULL)
    arrayVecT1[0] = v1; arrayVecT1[1] = v2; arrayVecT1[2] = v3; 
  addTriangle (v1, v2, v3);
  if (arrayVecT2 != NULL)
    arrayVecT2[0] = v1; arrayVecT2[1] = v3; arrayVecT2[2] = v4; 
  addTriangle (v1, v3, v4);
}

void CollisionModel3DImpl::setTransform(const Matrix3D& m)
{
  m_Transform=m;
  if (m_Static) m_InvTransform=m_Transform.Inverse();
}

void CollisionModel3DImpl::finalize()
{
  if (m_Final) Inconsistency::error();
  // Prepare initial triangle list
  m_Final=true;
  for(unsigned i=0;i<m_Triangles.size();i++)
  {
    BoxedTriangle& bt=m_Triangles[i];
    m_Root.m_Boxes.push_back(&bt);
  }
  int logdepth=0;
  for(int num=m_Triangles.size();num>0;num>>=1,logdepth++);
  m_Root.m_logdepth=int(logdepth*1.5f);
  m_Root.divide(0);
}

__CD__END
