function [ result ] = show_fourier(image_name)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    
    % reference: http://courses.engr.illinois.edu/cs498dh/fa2011/projects/hybrid/ComputationalPhotography_ProjectHybrid.html
    % 1. read in image and change it to gray
    % 2. do fast fourier transformation
    % 3. shift fourier 
    % 4. obtain the log of the abs value
    % 5. scale data and display object
    result = imagesc(log(abs(fftshift(fft2(rgb2gray(imread(image_name)))))));
    
    %imwrite(result, 'output.jpg');
    
    
end

