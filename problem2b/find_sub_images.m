function [red_rec, green_rec, blue_rec] = find_sub_images(image1)
   
    image1 = imread(image1);
    [x, y] = size(image1);
    
    %cut all white surroundings
    x_start = 0;
    x_end = 0;
    y_start = 0;
    y_end = 0;
    
    x_half = floor(x/2);
    y_half = floor(y/2);
    for i=1:1:y
        if (image1(x_half, i) < 25)
            y_start = i;
            break
        end
    end
    
    for i=y:-1:1
        if (image1(x_half, i) < 25)
            y_end = i;
            break
        end
    end
    
    for i=1:1:x
        if (image1(i, y_half) < 25)
            x_start = i;
            break
        end
    end
    
    for i=x:-1:1
        if (image1(i, y_half) < 25)
            x_end = i;
            break
        end
    end
    
    image2 = image1(x_start:x_end,y_start:y_end);
    
    [up1, down1] = findUpDown(image2, floor(x*1/6));
    [up2, down2] = findUpDown(image2, floor(x*1/2));
    [up3, down3] = findUpDown(image2, floor(x*5/6));
    
    r1 = x_start + up1;
    r2 = y_start;
    r3 = y_end - y_start;
    r4 = down1 - up1;
    
    g1 = x_start + up2;
    g2 = y_start;
    g3 = y_end - y_start;
    g4 = down2 - up2;
    
    b1 = x_start + up3;
    b2 = y_start;
    b3 = y_end - y_start;
    b4 = down3 - up3;
    
    
    
    red_rec = [r1 r2 r3 r4];
    green_rec = [g1 g2 g3 g4];
    blue_rec = [b1 b2 b3 b4];
    
    
    
    
    
    %rImage = image2(up1:down1,:);
    %gImage = image2(up2:down2,:);
    %bImage = image2(up3:down3,:);
    
end

function  [up, down] = findUpDown(image, idx)

    [x, y] = size(image);
    
    up = idx;
    down = idx;
    
    for i=idx:1:x
        if (image(i,floor(y/2)) < 25)
            down = i;
            break
        end
    end
    
    for i=idx:-1:1
        if (image(i,floor(y/2)) < 25)
            up = i;
            break
        end
    end
end



