% Corner Percolation

max_loops = 10^4;

down_up = (-1)^floor(rand+0.5); % line vector
% = 1 => goes up (resp. down) in an even (resp. odd) number
% = -1 vice versa
left_right = (-1)^floor(rand+0.5); % analogous to down_up, column vector
actual_du_ind = 1; % actual down_up index
actual_lr_ind = 1; % actual left_right index
hor_range = [0 0];
ver_range = [0 0];

path = [0; 0]; % [x; y]
ind_path = 1; % length(path) = ind_path-1

another_loop = 1;

if rand >= 0.5 % move first in the horizontal direction
    while another_loop ~= 0 && ind_path <= max_loops
        % horiz. movement
        if mod(path(1,ind_path),2) == 0
            p_or_m = 1;
        else
            p_or_m = -1;
        end
        path = [path [path(1,ind_path)+p_or_m*left_right(actual_lr_ind); path(2,ind_path)]];
        ind_path = ind_path+1;
        if path(1,ind_path) < hor_range(1)
            hor_range(1) = path(1,ind_path);
            down_up = [(-1)^floor(rand+0.5) down_up];
            actual_du_ind = 1;
        elseif path(1,ind_path) > hor_range(2)
            hor_range(2) = path(1,ind_path);
            down_up = [down_up (-1)^floor(rand+0.5)];
            actual_du_ind = actual_du_ind+1;
        else
            actual_du_ind = actual_du_ind+p_or_m*left_right(actual_lr_ind);
        end
        % vert. movement
        if mod(path(2,ind_path),2) == 0
            p_or_m = 1;
        else
            p_or_m = -1;
        end
        path = [path [path(1,ind_path); path(2,ind_path)+p_or_m*down_up(actual_du_ind)]];
        ind_path = ind_path+1;
        if path(2,ind_path) < ver_range(1)
            ver_range(1) = path(2,ind_path);
            left_right = [left_right; (-1)^floor(rand+0.5)];
            actual_lr_ind = actual_lr_ind+1;
        elseif path(2,ind_path) > ver_range(2)
            ver_range(2) = path(2,ind_path);
            left_right = [(-1)^floor(rand+0.5); left_right];
            actual_lr_ind = 1;
        else
            actual_lr_ind = actual_lr_ind-p_or_m*down_up(actual_du_ind);
        end
        % verify if another loop is necessary
        another_loop = max(abs(path(:,ind_path)));
    end
else % move first in the vertical direction
    while another_loop ~= 0 && ind_path <= max_loops
        % vert. movement
        if mod(path(2,ind_path),2) == 0
            p_or_m = 1;
        else
            p_or_m = -1;
        end
        path = [path [path(1,ind_path); path(2,ind_path)+p_or_m*down_up(actual_du_ind)]];
        ind_path = ind_path+1;
        if path(2,ind_path) < ver_range(1)
            ver_range(1) = path(2,ind_path);
            left_right = [left_right; (-1)^floor(rand+0.5)];
            actual_lr_ind = actual_lr_ind+1;
        elseif path(2,ind_path) > ver_range(2)
            ver_range(2) = path(2,ind_path);
            left_right = [(-1)^floor(rand+0.5); left_right];
            actual_lr_ind = 1;
        else
            actual_lr_ind = actual_lr_ind-p_or_m*down_up(actual_du_ind);
        end
        % horiz. movement
        if mod(path(1,ind_path),2) == 0
            p_or_m = 1;
        else
            p_or_m = -1;
        end
        path = [path [path(1,ind_path)+p_or_m*left_right(actual_lr_ind); path(2,ind_path)]];
        ind_path = ind_path+1;
        if path(1,ind_path) < hor_range(1)
            hor_range(1) = path(1,ind_path);
            down_up = [(-1)^floor(rand+0.5) down_up];
            actual_du_ind = 1;
        elseif path(1,ind_path) > hor_range(2)
            hor_range(2) = path(1,ind_path);
            down_up = [down_up (-1)^floor(rand+0.5)];
            actual_du_ind = actual_du_ind+1;
        else
            actual_du_ind = actual_du_ind+p_or_m*left_right(actual_lr_ind);
        end
        % verify if another loop is necessary
        another_loop = max(abs(path(:,ind_path)));
    end
end

fprintf('Number of Loops: %d\n',ind_path-1)
plot(path(1,:),path(2,:))
axis([hor_range+[-1 1] ver_range+[-1 1]])
axis equal