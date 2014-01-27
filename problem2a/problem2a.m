function  result = problem2a(image_name)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    image = imread(image_name);
    
    
    red_rec = [191 147 3530 3011];
    green_rec = [3370 119 3530 3011];
    blue_rec = [6522 109 3530 3011];
    
    %rImage = image(191:3202,147:3674);
    %gImage = image(3370:6381,119:3646);
    %bImage = image(6522:9533,109:3636);
    
    result = make_color(image, red_rec, green_rec, blue_rec);

    imwrite(result, 'output.tif');
    
end

function result = make_color(image, red_rec, green_rec, blue_rec)
    rImage = image(red_rec(1):red_rec(1)+red_rec(4), red_rec(2):red_rec(2)+red_rec(3));
    gImage = image(green_rec(1):green_rec(1)+green_rec(4), green_rec(2):green_rec(2)+green_rec(3));
    bImage = image(blue_rec(1):blue_rec(1)+blue_rec(4), blue_rec(2):blue_rec(2)+blue_rec(3));
    
    
    [rx, ry] = size(rImage);
    [gx, gy] = size(gImage);
    [bx, by] = size(bImage);
    
    
    newx = min(rx, min(gx, bx));
    newy = min(ry, min(gy, by));
    
    rImage = imresize(rImage, [newx newy]);
    gImage = imresize(gImage, [newx newy]);
    bImage = imresize(bImage, [newx newy]);

    result = cat(3, rImage, gImage, bImage);

end
































