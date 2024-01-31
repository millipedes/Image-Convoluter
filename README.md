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
\[ G(j, i) = \frac{1}{{2\pi\sigma^2}} e^{-\frac{{j^2 + i^2}}{{2\sigma^2}}} \]
where the domain of i and j are [-R, R] for some radius R of the kernel and some
standard deviation \[ \sigma \].

The Uniform kernel can be expressed as:
\[ \frac{1}{k} \]
for some uniform constant k.
