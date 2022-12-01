#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include <iostream>
#include "AMReX_MLMG.H"
#include "AMReX_Print.H"

namespace amr_wind::io {

void print_banner(MPI_Comm /*comm*/, std::ostream& /*out*/);

void print_usage(MPI_Comm /*comm*/, std::ostream& /*out*/);

void print_error(MPI_Comm /*comm*/, const std::string& msg);

void print_summary(std::ostream&);

void print_mlmg_header(const std::string& /*key*/);

template <typename MF>
void print_mlmg_info(const std::string& solve_name, const amrex::MLMGT<MF>& mlmg)
{
    const int name_width = 26;
    amrex::Print() << "  " << std::setw(name_width) << std::left << solve_name
                   << std::setw(6) << std::right << mlmg.getNumIters()
                   << std::setw(22) << std::right << mlmg.getInitResidual()
                   << std::setw(22) << std::right << mlmg.getFinalResidual()
                   << std::endl;
}

void print_mlmg_info(const std::string& solve_name, const amrex::Any& mlmg);

void print_tpls(std::ostream& /*out*/);

} // namespace amr_wind::io

#endif /* CONSOLE_IO_H */
