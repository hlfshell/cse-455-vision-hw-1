from uwimg import *
im = load_image("data/dog.jpg")
res = colorize_sobel(im)
save_image(res, "colorized_sobel")
