#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "image.h"
#define TWOPI 6.2831853

void l1_normalize(image im)
{
    float sum = 0;

    for(int c = 0; c < im.c; c++){
        for(int y = 0; y < im.h; y++){
            for(int x = 0; x < im.w; x++){
                float value = get_pixel(im, x, y, c);
                sum += value;
            }
        }
    }

    float average = sum / (im.w *im.h * im.c);

    for(int c = 0; c < im.c; c++){
        for(int y = 0; y < im.h; y++){
            for(int x = 0; x < im.w; x++){
                float value = get_pixel(im, x, y, c);
                set_pixel(im, x, y, c, value / average);
            }
        }
    }
}

image make_box_filter(int w)
{
    image filter = make_image(w, w, 1);
    float total = w * w;
    for(int i = 0; i < w * w; i++){
        filter.data[i] = 1 / total;
    }
    return filter;
}

image convolve_image(image im, image filter, int preserve)
{
    assert(im.c == filter.c || filter.c == 1);

    image convolved;
    int fOffset = filter.w / 2;
    float sum = 0;
    float fValue;
    int nx, ny;
    float imValue;

    if(preserve == 1){
        convolved = make_image(im.w, im.h, im.c);

        for(int c = 0; c < im.c; c++){
            for(int y = 0; y < im.h; y++){
                for(int x = 0; x < im.w; x++){

                    sum = 0;

                    for(int fy = 0; fy < filter.h; fy++){
                        for(int fx = 0; fx < filter.w; fx++){
                            fValue = get_pixel(filter, fx, fx, 0);
                            
                            nx = (-1 * fOffset ) + fx;
                            ny = (-1 * fOffset ) + fy;

                            // //Zero padding = results in a 0 to
                            // //this piece of the convolution
                            // if(x < 0 || y < 0){
                            //     continue;
                            // } else if(x >= im.w || y >= im.h) {
                            //     continue;
                            // }

                            imValue = get_pixel(im, nx, ny, c);
                            sum += fValue * imValue;
                            // printf("(%d, %d) C (%d, %d)=> (%d,%d) :: %f * %f = %f\n", x, y, fx, fy, nx, ny, fValue, imValue, sum);
                        }
                    }
                    set_pixel(convolved, x, y, c, sum);
                }
            }
        }

    } else {
        convolved = make_image(im.w, im.h, 1);

        for(int y = 0; y < im.h; y++){
            for(int x = 0; x < im.w; x++){
                float sum = 0;
                
                for(int fy = 0; fy < filter.h; fy++){
                    for(int fx = 0; fx < filter.w; fx++){
                        float fValue = get_pixel(filter, fx, fx, 1);
                        
                        int nx = (-1 * fOffset ) + fx;
                        int ny = (-1 * fOffset ) + fy;

                        // //Zero padding = results in a 0 to
                        // //this piece of the convolution
                        // if(x < 0 || y < 0){
                        //     continue;
                        // } else if(x >= im.w || y >= im.h) {
                        //     continue;
                        // }

                        for(int c = 0; c < im.c; c++){
                            float imValue = get_pixel(im, nx, ny, c);
                            sum += fValue * imValue;
                        }
                    }
                }

                set_pixel(convolved, x, y, 1, sum);
            }
        }
    }

    return convolved;
}

image make_highpass_filter()
{
    // TODO
    return make_image(1,1,1);
}

image make_sharpen_filter()
{
    // TODO
    return make_image(1,1,1);
}

image make_emboss_filter()
{
    // TODO
    return make_image(1,1,1);
}

// Question 2.2.1: Which of these filters should we use preserve when we run our convolution and which ones should we not? Why?
// Answer: TODO

// Question 2.2.2: Do we have to do any post-processing for the above filters? Which ones and why?
// Answer: TODO

image make_gaussian_filter(float sigma)
{
    // TODO
    return make_image(1,1,1);
}

image add_image(image a, image b)
{
    // TODO
    return make_image(1,1,1);
}

image sub_image(image a, image b)
{
    // TODO
    return make_image(1,1,1);
}

image make_gx_filter()
{
    // TODO
    return make_image(1,1,1);
}

image make_gy_filter()
{
    // TODO
    return make_image(1,1,1);
}

void feature_normalize(image im)
{
    // TODO
}

image *sobel_image(image im)
{
    // TODO
    return calloc(2, sizeof(image));
}

image colorize_sobel(image im)
{
    // TODO
    return make_image(1,1,1);
}
