#include "colmap/exe/mvs.h"

#include "colmap/sensor/bitmap.h"

#include <iostream>

#include <FreeImage.h>

int main() {
  std::string path =
      "/mnt/luchuanchuan/project/pc_seg/data/zhuhai1440/images_2000/"
      "mask2former_output/labels_m2f/1A0012.png";
  const FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path.c_str(), 0);
  if (format == FIF_UNKNOWN) {
    return false;
  }
  std::cout << format << std::endl;
  colmap::Bitmap bitmap;
  bitmap.Read(path, 0, 1);
  uint16_t label;
  bitmap.GetPixel(491, 327, &label);

  std::cout << label << std::endl;

  return 0;
}