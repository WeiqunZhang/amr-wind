AMREX_HOME ?= ../../amrex
TOP = ..

EBASE = amr_wind

BL_NO_FORT = FALSE

DIM = 3

PRECISION  = DOUBLE

TINY_PROFILE = FALSE

DEBUG      = TRUE
DEBUG      = FALSE

COMP	   = gnu

USE_MPI    = FALSE
USE_OMP    = FALSE
USE_CUDA   = FALSE

USE_HYPRE = FALSE

USE_EB = FALSE


AMREX_XSDK = TRUE

include $(AMREX_HOME)/Tools/GNUMake/Make.defs

#These are the directories in amr-wind/amr-wind
Bdirs := amr-wind
Bdirs += amr-wind/boundary_conditions
Bdirs += amr-wind/convection
Bdirs += amr-wind/core
Bdirs += amr-wind/derive
Bdirs += amr-wind/diffusion
Bdirs += amr-wind/equation_systems
Bdirs += amr-wind/equation_systems/density
Bdirs += amr-wind/equation_systems/icns
Bdirs += amr-wind/equation_systems/icns/source_terms
Bdirs += amr-wind/equation_systems/sdr
Bdirs += amr-wind/equation_systems/temperature
Bdirs += amr-wind/equation_systems/tke
Bdirs += amr-wind/physics
Bdirs += amr-wind/prob
Bdirs += amr-wind/projection
Bdirs += amr-wind/setup
Bdirs += amr-wind/transport_models
Bdirs += amr-wind/turbulence
Bdirs += amr-wind/turbulence/LES
Bdirs += amr-wind/utilities
Bdirs += amr-wind/utilities/tagging
Bdirs += amr-wind/wind_energy

ifeq ($(AMREX_WIND_ENABLE_MASA),TRUE)
  Bdirs += amr-wind/mms
endif

Bpack += $(foreach dir, $(Bdirs), $(TOP)/$(dir)/Make.package)
Blocs += $(foreach dir, $(Bdirs), $(TOP)/$(dir))

include $(Bpack)
INCLUDE_LOCATIONS += $(Blocs) ..
VPATH_LOCATIONS   += $(Blocs)

#These are the directories in AMReX
Pdirs := Base AmrCore Boundary LinearSolvers/MLMG LinearSolvers/Projections

Ppack += $(foreach dir, $(Pdirs), $(AMREX_HOME)/Src/$(dir)/Make.package)
include $(Ppack)

all: $(executable)
	$(SILENT) $(RM) AMReX_buildInfo.cpp
	@echo SUCCESS

# job_info support
CEXE_sources += AMReX_buildInfo.cpp
CEXE_headers += $(AMREX_HOME)/Tools/C_scripts/AMReX_buildInfo.H
INCLUDE_LOCATIONS +=  $(AMREX_HOME)/Tools/C_scripts

AMReX_buildInfo.cpp:
	$(AMREX_HOME)/Tools/C_scripts/makebuildinfo_C.py \
          --amrex_home "$(AMREX_HOME)" \
          --COMP "$(COMP)" --COMP_VERSION "$(COMP_VERSION)" \
          --CXX_comp_name "$(CXX)" --CXX_flags "$(CXXFLAGS) $(CPPFLAGS) $(includes)" \
          --F_comp_name "$(F90)" --F_flags "$(F90FLAGS)" \
          --link_flags "$(LDFLAGS)" --libraries "$(libraries)" \
          --GIT "$(TOP) $(AMREX_HOME)"

include $(AMREX_HOME)/Tools/GNUMake/Make.rules

clean::
	$(SILENT) $(RM) AMReX_buildInfo.cpp
