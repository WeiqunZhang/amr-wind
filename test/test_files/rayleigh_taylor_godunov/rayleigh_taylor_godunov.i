max_step                = 20

incflo.fixed_dt         = 0.1
incflo.cfl              = 0.9           # CFL factor
incflo.init_shrink      = 1.0

amr.plot_int            =   10          # Steps between plot files
amr.check_int           =  -100         # Steps between checkpoint files
incflo.mu               =   0.001       # Dynamic viscosity coefficient
incflo.mu_s             =   0.001       # Scalar diffusion coefficient mu (mu = rho * nu)

amr.max_level           =   2
amr.regrid_int          =   2

amr.n_cell              =   16 16 32    # Grid cells at coarsest AMRlevel
amr.max_grid_size       =   8 8 8       # Max grid size at AMR levels
amr.blocking_factor     =   8           # Blocking factor for grids

geometry.prob_lo        =  0.  0.  0.   # Lo corner coordinates
geometry.prob_hi        =  0.5 0.5 1.0  # Hi corner coordinates

geometry.is_periodic    =   1   1   0   # Periodicity x y z (0/1)

# Boundary
zlo.type                = "sw"
zhi.type                = "sw"

incflo.probtype         =  5

incflo.gravity          = 0. 0. -0.3

incflo.gradrhoerr       = 0.1

amr.plt_ccse_regtest    =  1
amr.plt_vort            =  1

incflo.use_godunov      = true
incflo.constant_density = false
incflo.advect_tracer    = true

incflo.diffusion_type   = 1             # 0 = Explicit, 1 = Crank-Nicolson, 2 = Implicit

incflo.verbose          =   0           # incflo_level

mac_proj.mg_rtol        = 1.e-12
