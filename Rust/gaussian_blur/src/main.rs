extern crate image;

use std::fs::File;
use std::path::Path;
use std::env;

fn main() {
	let args: Vec<_> = env::args().collect();
  let ref radius = args[1];
  let ref file_in = args[2];
  let ref file_out = args[3];

	println!("Trying to save {} with a blur radius of {} as {}", file_in, radius, file_out);

	let img = image::open(&Path::new(&file_in)).unwrap();
	let blurred_image = img.blur(3.0);

	let ref mut fout = File::create(&Path::new(&file_out)).unwrap();
	let _ = blurred_image.save(fout, image::JPEG);

	println!("Saved {} with a blur radius of {} as {}", file_in, radius, file_out);
}
