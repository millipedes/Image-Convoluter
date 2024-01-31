# :sunrise_over_mountains: Image Convoluter
This program convolutes images. It is is meant as a demonstrative example of two
theoretical concepts:
  - Discrete Kernel
  - Convolution

Generally speaking these methods are used by renderers to make images be more
appealing to the viewer, but the same techniques can be applied to an image to
make it more blurry.

## :corn: Supported Kernels
  - Gaussian
  - Uniform

The Gaussian kernel can be expressed as:

![Gaussian Kernel](figures/gaussian_kernel_2d.png)

where the domain of i and j are [-R, R] for some radius R of the kernel and some
standard deviation sigma.

The Uniform kernel can be expressed as: 1/k for all i and j in domain [-R, R]
for some uniform constant k.
