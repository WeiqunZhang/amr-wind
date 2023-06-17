#include "amr-wind/wind_energy/ABLFillInflow.H"

namespace amr_wind {

ABLFillInflow::ABLFillInflow(
    Field& field,
    const amrex::AmrCore& mesh,
    const SimTime& time,
    const ABLBoundaryPlane& bndry_plane)
    : FieldFillPatchOps<FieldBCNoOp>(
          field, mesh, time, FieldInterpolator::CellConsLinear)
    , m_bndry_plane(bndry_plane)
{}

ABLFillInflow::~ABLFillInflow() = default;

void ABLFillInflow::fillpatch(
    int lev,
    amrex::Real time,
    amrex::MultiFab& mfab,
    const amrex::IntVect& nghost,
    const FieldState fstate)
{
    amrex::Print() << "xxxxx calling ABLFillInflow::fillpatch nghost = "
                   << nghost << " ncomp = " << mfab.nComp() << " lev = " << lev << "\n";

    if (lev == 1 && mfab.nComp() == 3) {
        amrex::system::verbose = 100;
    } else {
        amrex::system::verbose = 1;
    }

    FieldFillPatchOps<FieldBCNoOp>::fillpatch(lev, time, mfab, nghost, fstate);

    if (lev == 1 && mfab.nComp() == 3) {
        amrex::Print() << "   Right after fillpatch: mfab.contains_nan(2, 1, IntVect(1,0,0)): " << mfab.contains_nan(2, 1, amrex::IntVect(1,0,0)) << "\n";
    }

    m_bndry_plane.populate_data(lev, time, m_field, mfab);

    if (lev == 1 && mfab.nComp() == 3) {
        amrex::Print() << "    mfab.contains_nan(0,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(1,0,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(1,0,0)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(2,0,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(2,0,0)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(3,0,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(3,0,0)) << "\n";

        amrex::Print() << "    mfab.contains_nan(1,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(1,0,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(1,0,0)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(2,0,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(2,0,0)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(3,0,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(3,0,0)) << "\n";

        amrex::Print() << "    mfab.contains_nan(2,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(1,0,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(1,0,0)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(2,0,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(2,0,0)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(3,0,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(3,0,0)) << "\n";

        amrex::Print() << "    mfab.contains_nan(0,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(0,1,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,1,0)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(0,2,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,2,0)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(0,3,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,3,0)) << "\n";
                                                                 
        amrex::Print() << "    mfab.contains_nan(1,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(0,1,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,1,0)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(0,2,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,2,0)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(0,3,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,3,0)) << "\n";
                                                                 
        amrex::Print() << "    mfab.contains_nan(2,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(0,1,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,1,0)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(0,2,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,2,0)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(0,3,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,3,0)) << "\n";

        amrex::Print() << "    mfab.contains_nan(0,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(0,0,1)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,0,1)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(0,0,2)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,0,2)) << "\n"
                       << "    mfab.contains_nan(0,1,amrex::IntVect(0,0,3)) = "
                       <<      mfab.contains_nan(0,1,amrex::IntVect(0,0,3)) << "\n";
                                                                  
        amrex::Print() << "    mfab.contains_nan(1,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(0,0,1)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,0,1)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(0,0,2)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,0,2)) << "\n"
                       << "    mfab.contains_nan(1,1,amrex::IntVect(0,0,3)) = "
                       <<      mfab.contains_nan(1,1,amrex::IntVect(0,0,3)) << "\n";
                                                                  
        amrex::Print() << "    mfab.contains_nan(2,1,amrex::IntVect(0,0,0)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,0,0)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(0,0,1)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,0,1)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(0,0,2)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,0,2)) << "\n"
                       << "    mfab.contains_nan(2,1,amrex::IntVect(0,0,3)) = "
                       <<      mfab.contains_nan(2,1,amrex::IntVect(0,0,3)) << "\n";

        amrex::Print() << " ba = " << mfab.boxArray() << "\n";

        print_nan(mfab, 2, 1, amrex::IntVect(1,1,0));

        amrex::Abort("xxxxx");
    } else {
        amrex::Print() << "xxxxx END: nan? " << mfab.contains_nan(0,mfab.nComp(),nghost) << std::endl;
    }
}

void ABLFillInflow::fillpatch_from_coarse(
    int lev,
    amrex::Real time,
    amrex::MultiFab& mfab,
    const amrex::IntVect& nghost,
    const FieldState fstate)
{
    amrex::Print() << "xxxxx calling ABLFillInflow::fillpatch_from_coarse nghost = "
                   << nghost << " ncomp = " << mfab.nComp() << " lev = " << lev << "\n";

    FieldFillPatchOps<FieldBCNoOp>::fillpatch_from_coarse(
        lev, time, mfab, nghost, fstate);

    m_bndry_plane.populate_data(lev, time, m_field, mfab);

    amrex::Print() << "xxxxx END: nan? " << mfab.contains_nan(0,mfab.nComp(),nghost) << std::endl;
}

void ABLFillInflow::fillphysbc(
    int lev,
    amrex::Real time,
    amrex::MultiFab& mfab,
    const amrex::IntVect& nghost,
    const FieldState fstate)
{
    amrex::Print() << "xxxxx calling ABLFillInflow::fillphysbc nghost = "
                   << nghost << " ncomp = " << mfab.nComp() << " lev = " << lev << "\n";

    FieldFillPatchOps<FieldBCNoOp>::fillphysbc(lev, time, mfab, nghost, fstate);

    m_bndry_plane.populate_data(lev, time, m_field, mfab);

    amrex::Print() << "xxxxx END: nan? " << mfab.contains_nan(0,mfab.nComp(),nghost) << std::endl;
}

void ABLFillInflow::fillpatch_sibling_fields(
    int lev,
    amrex::Real time,
    amrex::Array<amrex::MultiFab*, AMREX_SPACEDIM>& mfabs,
    amrex::Array<amrex::MultiFab*, AMREX_SPACEDIM>& ffabs,
    amrex::Array<amrex::MultiFab*, AMREX_SPACEDIM>& cfabs,
    const amrex::IntVect& nghost,
    const amrex::Vector<amrex::BCRec>& bcrec,
    const FieldState fstate,
    const FieldInterpolator itype)
{
    amrex::Print() << "xxxxx calling ABLFillInflow::fillpatch nghost = "
                   << nghost << " lev = " << lev << "\n";

    // For an ABL fill, we just foextrap the mac velocities
    amrex::Vector<amrex::BCRec> lbcrec(m_field.num_comp());
    const auto& ibctype = m_field.bc_type();
    for (amrex::OrientationIter oit; oit != nullptr; ++oit) {
        auto ori = oit();
        const auto side = ori.faceDir();
        const auto bct = ibctype[ori];
        const int dir = ori.coordDir();
        for (int i = 0; i < m_field.num_comp(); ++i) {
            if (bct == BC::mass_inflow) {
                if (side == amrex::Orientation::low) {
                    lbcrec[i].setLo(dir, amrex::BCType::foextrap);
                } else {
                    lbcrec[i].setHi(dir, amrex::BCType::foextrap);
                }
            } else {
                if (side == amrex::Orientation::low) {
                    lbcrec[i].setLo(dir, bcrec[i].lo(dir));
                } else {
                    lbcrec[i].setHi(dir, bcrec[i].hi(dir));
                }
            }
        }
    }

    FieldFillPatchOps<FieldBCNoOp>::fillpatch_sibling_fields(
        lev, time, mfabs, ffabs, cfabs, nghost, lbcrec, fstate, itype);

    for (int i = 0; i < static_cast<int>(mfabs.size()); i++) {
        m_bndry_plane.populate_data(lev, time, m_field, *mfabs[i], 0, i);
    }
}

} // namespace amr_wind
