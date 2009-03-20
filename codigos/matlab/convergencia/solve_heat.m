% function [ u ] = solve_heat( N, T )
%
% Resolve a equacao do calor no toro R\Z discretizado em "N" partes.
% "u" eh a solucao no tempo "T" com a gaussiana como dado inicial 

function [ u ] = solve_heat( N, T )

    eps = 1E-4;
    keepRunning = true;
    n = 1;
    
    x = 0 : 1/N : 1;
    h = 1/N;
   
    u = quad( @(y)(exp(-4*pi*(y-1/2).^2 )), 0, 1 );
    while keepRunning,        
        an = quadgk( @(y)(exp(-4*pi*(y-1/2).^2 ).*cos(2*pi*n*y)), 0, 1 );
        bn = quadgk( @(y)(exp(-4*pi*(y-1/2).^2 ).*sin(2*pi*n*y)), 0, 1 );                
                
        u0 = u;
        u = u + 2 * exp(-n^2 * T) * ( an * cos(2*pi*n*x) + bn*sin(2*pi*n*x) );

        if ( sqrt(h) * norm( u0 - u, 2 ) < eps ),
            keepRunning = false;
        end
        
        n = n + 1;        
    end 
end
