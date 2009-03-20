% function [ meas ] = meas( X, epsilon )
%
% meas{ |X| > epsilon }

function [ meas ] = meas( X, epsilon )

    N = size( X, 2 ) - 1;
    Q = abs( X ) > epsilon;
    
    meas = 1/N * sum( Q );
end