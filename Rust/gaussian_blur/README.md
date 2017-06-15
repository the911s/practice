# Rust `image` crate vs. ImageMagick `convert`

Compare Rust's gaussian blur implementation to ImageMagick's (written in C).

```
gaussian_blur [master●●] time target/release/gaussian_blur 3 screen_shot.png output.png
Trying to save screen_shot.png with a blur radius of 3 as output.png
Saved screen_shot.png with a blur radius of 3 as output.png
target/release/gaussian_blur 3 screen_shot.png output.png  1.57s user 0.16s system 99% cpu 1.733 total

gaussian_blur [master●●●] time convert -gaussian-blur 0x3 screen_shot.png output-im.png
convert -gaussian-blur 0x3 screen_shot.png output-im.png  7.04s user 0.03s system 99% cpu 7.099 total
```
