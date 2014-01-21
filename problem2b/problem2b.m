function  result = problem2b(image_name)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    image1 = imread(image_name);
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
    
        
    %divide 3 images
    [up1, down1] = findUpDown(image2, floor(x*1/6));
    [up2, down2] = findUpDown(image2, floor(x*1/2));
    [up3, down3] = findUpDown(image2, floor(x*5/6));
    
    rImage = image2(up1:down1,:);
    gImage = image2(up2:down2,:);
    bImage = image2(up3:down3,:);
    
    %imshow(rImage);
    %imshow(gImage);
    %imshow(bImage);
    
    [rx, ry] = size(rImage);
    [gx, gy] = size(gImage);
    [bx, by] = size(bImage);
    
    rcx = floor(rx/2)
    %rcy = floor(ry/2);
    gcx = floor(gx/2)
    %gcy = floor(gy/2);
    bcx = floor(bx/2)
    %bcy = floor(by/2);
    
    half = floor(1/2 * min(rx, min(gx, bx)))
    
    rImage = rImage(rcx-half+1:rcx+half,:);
    gImage = gImage(gcx-half+1:gcx+half,:);
    bImage = bImage(bcx-half+1:bcx+half,:);
    
    
    
    result = cat(3, rImage, gImage, bImage);
    
    
    
end


function  [up, down] = findUpDown(image, idx)

    [x, y] = size(image)
    
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
