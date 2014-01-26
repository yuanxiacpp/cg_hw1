function [low, high] = hybrid_split(image)
    %image = rgb2gray(image);
    H = fspecial('gaussian', 35, 20);
    high = imfilter(image, H);
    low = image - high;
end
