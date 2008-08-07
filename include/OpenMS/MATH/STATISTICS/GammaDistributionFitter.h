// -*- mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework
// --------------------------------------------------------------------------
//  Copyright (C) 2003-2008 -- Oliver Kohlbacher, Knut Reinert
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------
// $Maintainer: Andreas Bertsch $
// --------------------------------------------------------------------------
//
#ifndef OPENMS_MATH_STATISTICS_GAMMADISTRIBUTIONFITTER_H
#define OPENMS_MATH_STATISTICS_GAMMADISTRIBUTIONFITTER_H

#include <OpenMS/DATASTRUCTURES/String.h>
#include <OpenMS/CONCEPT/Types.h>
#include <OpenMS/DATASTRUCTURES/DPosition.h>

#include <vector>

// gsl includes
#include <gsl/gsl_rng.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multifit_nlin.h>


namespace OpenMS
{
  /** @brief Implements a fitter for the Gamma distribution.

      This class fits a Gamma distribution to a number of data points.
      The results as well as the initial guess are specified using the struct 
			GammaDistributionFitResult.

      The formula with the fitted parameters can be transformed into a
      gnuplot formula using getGnuplotFormulai() after fitting.

			The implementation is done using the gsl fitting algorithms.
	*/
	class GammaDistributionFitter
	{
		public:

			/// struct to represent the parameters of a gamma distribution
			struct GammaDistributionFitResult
			{
				public:

					/// parameter b of the gamma distribution
					double b;

					/// parameter p of the gamma distribution
					double p;
			};
	
			/** @name Constructors and destructors
			*/
			//@{
			/// Default constructor
			GammaDistributionFitter();

			/// Copy constructor
			GammaDistributionFitter(const GammaDistributionFitter& rhs);

			/// Destructor
			virtual ~GammaDistributionFitter();
			//@}

			/// assignment operator 
			GammaDistributionFitter& operator = (const GammaDistributionFitter& rhs);

			/** tries to fit the given data points onto a gamma distribution

					@param points Input parameter which represents the point used for the fitting

			*/
			GammaDistributionFitResult fit(std::vector<DPosition<2> >& points);

			/// returns the initial parmaters b and p of the gamma distribution
			const GammaDistributionFitResult& getInitialParameters() const;
			
			/// sets the gamma distribution start parameters b and p for the fitting 
			void setInitialParameters(const GammaDistributionFitResult& result);

			/// returns the gnuplot formula of the fitted gamma distribution
			const String& getGnuplotFormula() const;
			
		protected:
			
			static int gammaDistributionFitterf_(const gsl_vector* x, void* params, gsl_vector* f);

			static int gammaDistributionFitterdf_(const gsl_vector* x, void* params, gsl_matrix* J);

			static int gammaDistributionFitterfdf_(const gsl_vector* x, void* params, gsl_vector* f, gsl_matrix* J);

			void printState_(size_t iter, gsl_multifit_fdfsolver* s);
			
			GammaDistributionFitResult init_param_;
			
			String gnuplot_formula_;
	};
}

#endif

