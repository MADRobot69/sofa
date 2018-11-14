/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2018 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#ifndef SOFA_COMPONENT_MAPPING_BARYCENTRICMAPPERTRIANGLESETTOPOLOGY_INL
#define SOFA_COMPONENT_MAPPING_BARYCENTRICMAPPERTRIANGLESETTOPOLOGY_INL

#include "BarycentricMapperTriangleSetTopology.h"

namespace sofa
{

namespace component
{

namespace mapping
{


template <class In, class Out>
int BarycentricMapperTriangleSetTopology<In,Out>::addPointInTriangle ( const int triangleIndex, const SReal* baryCoords )
{
    helper::vector<MappingData>& vectorData = *(d_map.beginEdit());
    vectorData.resize ( d_map.getValue().size() +1 );
    MappingData& data = *vectorData.rbegin();
    d_map.endEdit();
    data.in_index = triangleIndex;
    data.baryCoords[0] = ( Real ) baryCoords[0];
    data.baryCoords[1] = ( Real ) baryCoords[1];
    return (int)d_map.getValue().size()-1;
}

template <class In, class Out>
int BarycentricMapperTriangleSetTopology<In,Out>::createPointInTriangle ( const typename Out::Coord& p, int triangleIndex, const typename In::VecCoord* points )
{
    SReal baryCoords[2];
    const Triangle& elem = this->m_fromTopology->getTriangle ( triangleIndex );
    const typename In::Coord p0 = ( *points ) [elem[0]];
    const typename In::Coord pA = ( *points ) [elem[1]] - p0;
    const typename In::Coord pB = ( *points ) [elem[2]] - p0;
    typename In::Coord pos = Out::getCPos(p) - p0;
    // First project to plane
    typename In::Coord normal = cross ( pA, pB );
    Real norm2 = normal.norm2();
    pos -= normal* ( ( pos*normal ) /norm2 );
    baryCoords[0] = ( Real ) sqrt ( cross ( pB, pos ).norm2() / norm2 );
    baryCoords[1] = ( Real ) sqrt ( cross ( pA, pos ).norm2() / norm2 );
    return this->addPointInTriangle ( triangleIndex, baryCoords );
}


template <class In, class Out>
helper::vector<Triangle> BarycentricMapperTriangleSetTopology<In,Out>::getElements()
{
    return this->m_fromTopology->getTriangles();
}

template <class In, class Out>
helper::vector<SReal> BarycentricMapperTriangleSetTopology<In,Out>::getBaryCoef(const Real* f)
{
    return getBaryCoef(f[0],f[1]);
}

template <class In, class Out>
helper::vector<SReal> BarycentricMapperTriangleSetTopology<In,Out>::getBaryCoef(const Real fx, const Real fy)
{
    helper::vector<SReal> triangleCoef{1-fx-fy, fx, fy};
    return triangleCoef;
}

template <class In, class Out>
void BarycentricMapperTriangleSetTopology<In,Out>::computeBase(Mat3x3d& base, const typename In::VecCoord& in, const Triangle& element)
{
    Mat3x3d mt;
    base[0] = in[element[1]]-in[element[0]];
    base[1] = in[element[2]]-in[element[0]];
    base[2] = cross(base[0],base[1]);
    mt.transpose(base);
    base.invert(mt);
}

template <class In, class Out>
void BarycentricMapperTriangleSetTopology<In,Out>::computeCenter(Vector3& center, const typename In::VecCoord& in, const Triangle& element)
{
    center = (in[element[0]]+in[element[1]]+in[element[2]])/3;
}

template <class In, class Out>
void BarycentricMapperTriangleSetTopology<In,Out>::computeDistance(double& d, const Vector3& v)
{
    d = std::max ( std::max ( -v[0],-v[1] ),std::max ( ( v[2]<0?-v[2]:v[2] )-0.01,v[0]+v[1]-1 ) );
}

template <class In, class Out>
void BarycentricMapperTriangleSetTopology<In,Out>::addPointInElement(const int elementIndex, const SReal* baryCoords)
{
    addPointInTriangle(elementIndex,baryCoords);
}

}}}


#endif
