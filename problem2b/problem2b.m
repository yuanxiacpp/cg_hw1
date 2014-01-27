function  result = problem2b(image)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    


    %divide 3 images
    [red_rec blue_rec green_rec] = find_sub_images(image);
    make_color(image, red_rec, blue_rec, green_rec);
        

    
    
    
end






