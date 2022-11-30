DEBUG = FALSE

USE_MPI  = TRUE
USE_OMP  = FALSE

USE_HYPRE = FALSE
USE_PETSC = FALSE
BL_NO_FORT = TRUE

COMP = gnu

DIM = 3

USE_HIP = TRUE
TINY_PROFILE = TRUE
USE_PARTICLES = TRUE

AMREX_HOME = ../amrex

include $(AMREX_HOME)/Tools/GNUMake/Make.defs

Pdirs_amrex := Base Boundary AmrCore LinearSolvers/MLMG Particle
Ppack += $(foreach dir, $(Pdirs_amrex), $(AMREX_HOME)/Src/$(dir)/Make.package)

Pdirs_amrwind := . core core/vs \
    boundary_conditions \
    convection \
    derive \
    diffusion \
    equation_systems \
    equation_systems/density \
    equation_systems/icns \
    equation_systems/icns/source_terms \
    equation_systems/levelset \
    equation_systems/sdr \
    equation_systems/sdr/source_terms \
    equation_systems/temperature \
    equation_systems/tke \
    equation_systems/tke/source_terms \
    equation_systems/vof \
    fvm \
    immersed_boundary \
    immersed_boundary/bluff_body \
    mesh_mapping_models \
    overset \
    physics \
    physics/multiphase \
    physics/udfs \
    projection \
    setup \
    transport_models \
    turbulence \
    turbulence/LES \
    turbulence/RANS \
    utilities \
    utilities/averaging \
    utilities/sampling \
    utilities/tagging \
    wind_energy \
    wind_energy/actuator \
    wind_energy/actuator/aero \
    wind_energy/actuator/disk \
    wind_energy/actuator/turbine \
    wind_energy/actuator/turbine/fast \
    wind_energy/actuator/wing

# utilities/ascent utilities/ncutils physics/mms

Ppack += $(foreach dir, $(Pdirs_amrwind), amr-wind/$(dir)/Make.package)
Pdirs += $(foreach dir, $(Pdirs_amrwind), amr-wind/$(dir))

AMREX_HYDRO_HOME = ../AMReX-Hydro
Pdirs_amrex_hydro := BDS Godunov MOL Projections Slopes Utils
Ppack += $(foreach dir, $(Pdirs_amrex_hydro), $(AMREX_HYDRO_HOME)/$(dir)/Make.package)
Pdirs += $(foreach dir, $(Pdirs_amrex_hydro), $(AMREX_HYDRO_HOME)/$(dir))

VPATH_LOCATIONS += $(Pdirs)
INCLUDE_LOCATIONS += $(Pdirs)

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
