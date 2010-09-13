function isOpen( i , j , l )
        print(i , j , l )
        return random() > ( 0.1*math.abs(i) + .3*math.abs(j) ) / 10
end
