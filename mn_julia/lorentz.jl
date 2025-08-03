using DifferentialEquations,Plots

function lorenz!(δu,u,p,t)
  x,y,z = u
  σ,ρ,β = p
  δu[1] = δx = σ *(y - x)
  δu[2] = δy = x *(ρ - z) - y
  δu[3] = δz = x *y - β *z
end

u0 = [1.0;0.0;0.0]
p = [10.0,28.0,8/3]
tspan = (0.0,100.0)

prob = ODEProblem(lorenz!,u0,tspan,p)
sol = solve(prob,saveat=0.05,reltol=1e-8,abstol=1e-8)


plt = plot3d(
    1,
    xlim = (-30, 30),
    ylim = (-30, 30),
    zlim = (0, 60),
    title = "Lorenz Attractor",
    marker = 2,
)
@gif for i=1:1000
    push!(plt, sol.u[i][1], sol.u[i][2], sol.u[i][3])
end every 10