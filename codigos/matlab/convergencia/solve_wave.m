% function [ u ] = solve_wave( u0, N, p, T )
%
% Resolve a equacao do transporte com velocidade c = p - (1-p) no toro R\Z 
% discretizado em N partes. 
% u eh a solucao de dado inicial u0 no tempo T.

function [ u ] = solve_wave( u0, N, p, T )

    % N = size( u0, 2 ) - 1;
    
    % ajusta a velocidade
    c = p - (1 - p);
    
    % define a grade
    h = 1/N;
    k = (2^20 - 1)/(2^20) * h;
    
    % tempo discreto 
    n = floor( T/k );
    
    lambda = k/h;
    
    u = u0;
    for i = 1 : n,
        u = 1/2*(1 + c*lambda)*shift_right(u) + 1/2*(1 - c*lambda)*shift_left(u);
    end 
end

function [ L ] = shift_left( X )
    
    m = size( X, 2 );
    L = [ X(2:m), X(1) ];
end

function [ R ] = shift_right( X )

    m = size( X, 2 );
    R = [ X(m), X( 1:(m-1) ) ];
end
