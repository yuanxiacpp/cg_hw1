function result = make_color(image, red_rec, green_rec, blue_rec)

    image = imread(image);

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

    imwrite(result, 'out.tiff');

end

