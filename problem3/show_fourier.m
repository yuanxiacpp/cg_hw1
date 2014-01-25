function [ result ] = show_fourier(image_name)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    
    result = imagesc(log(abs(fftshift(fft2(rgb2gray(imread(image_name)))))));
    
    %imwrite(result, 'output.jpg');
    
    
end

