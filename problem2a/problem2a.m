function  result = problem2a(image_name)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    image = imread(image_name);

    
    rImage = image(191:3202,147:3674);
    gImage = image(3370:6381,119:3646);
    bImage = image(6522:9533,109:3636);
    
    %imtool(rImage)
    %imtool(gImage)
    %imtool(bImage);
    
    %subplot(1,3,1), imshow(rImage)
    %subplot(1,3,2), imshow(gImage)
    %subplot(1,3,3), imshow(bImage)
    
    result = cat(3, rImage, gImage, bImage);

    
end
































