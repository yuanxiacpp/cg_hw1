function [result] = create_hybrid(low_file, high_file)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    low_image = imread(low_file);
    high_image = imread(high_file);
    
    [low_low, low_high] = hybrid_split(low_image);
    [high_low, high_high] = hybrid_split(high_image);
    
    result = low_low + high_high;

end

function [low, high] = hybrid_split(image)
    image = rgb2gray(image);
    H = fspecial('gaussian', 35, 20);
    high = imfilter(image, H);
    low = image - high;
end

