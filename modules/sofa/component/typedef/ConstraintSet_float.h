/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, v17.06                  *
*                (c) 2006-2017 INRIA, USTL, UJF, CNRS, MGH                    *
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



// File automatically generated by "generateTypedef"


#ifndef SOFA_TYPEDEF_ConstraintSet_float_H
#define SOFA_TYPEDEF_ConstraintSet_float_H

//Default files containing the declaration of the vector type
#include <sofa/defaulttype/VecTypes.h>
#include <sofa/defaulttype/RigidTypes.h>
#include <sofa/defaulttype/Mat.h>




#include <SofaConstraint/DOFBlockerLMConstraint.h>
#include <SofaConstraint/DistanceLMConstraint.h>
#include <SofaConstraint/DistanceLMContactConstraint.h>
#include <SofaConstraint/FixedLMConstraint.h>
#include <SofaConstraint/UnilateralInteractionConstraint.h>



//---------------------------------------------------------------------------------------------
//Typedef for DOFBlockerLMConstraint
typedef sofa::component::constraintset::DOFBlockerLMConstraint<sofa::defaulttype::StdRigidTypes<3, float> > DOFBlockerLMConstraintRigid3f;
typedef sofa::component::constraintset::DOFBlockerLMConstraint<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<3, float>, sofa::defaulttype::Vec<3, float>, float> > DOFBlockerLMConstraint3f;



//---------------------------------------------------------------------------------------------
//Typedef for DistanceLMConstraint
typedef sofa::component::constraintset::DistanceLMConstraint<sofa::defaulttype::StdRigidTypes<3, float> > DistanceLMConstraintRigid3f;
typedef sofa::component::constraintset::DistanceLMConstraint<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<3, float>, sofa::defaulttype::Vec<3, float>, float> > DistanceLMConstraint3f;



//---------------------------------------------------------------------------------------------
//Typedef for DistanceLMContactConstraint
typedef sofa::component::constraintset::DistanceLMContactConstraint<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<3, float>, sofa::defaulttype::Vec<3, float>, float> > DistanceLMContactConstraint3f;



//---------------------------------------------------------------------------------------------
//Typedef for FixedLMConstraint
typedef sofa::component::constraintset::FixedLMConstraint<sofa::defaulttype::StdRigidTypes<3, float> > FixedLMConstraintRigid3f;
typedef sofa::component::constraintset::FixedLMConstraint<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<3, float>, sofa::defaulttype::Vec<3, float>, float> > FixedLMConstraint3f;



//---------------------------------------------------------------------------------------------
//Typedef for UnilateralInteractionConstraint
typedef sofa::component::constraintset::UnilateralInteractionConstraint<sofa::defaulttype::StdVectorTypes<sofa::defaulttype::Vec<3, float>, sofa::defaulttype::Vec<3, float>, float> > UnilateralInteractionConstraint3f;





#ifdef SOFA_FLOAT
typedef DOFBlockerLMConstraintRigid3f DOFBlockerLMConstraintRigid3;
typedef DOFBlockerLMConstraint3f DOFBlockerLMConstraint3;
typedef DistanceLMConstraintRigid3f DistanceLMConstraintRigid3;
typedef DistanceLMConstraint3f DistanceLMConstraint3;
typedef DistanceLMContactConstraint3f DistanceLMContactConstraint3;
typedef FixedLMConstraintRigid3f FixedLMConstraintRigid3;
typedef FixedLMConstraint3f FixedLMConstraint3;
typedef UnilateralInteractionConstraint3f UnilateralInteractionConstraint3;
#endif

#endif