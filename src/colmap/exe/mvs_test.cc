#include "colmap/exe/mvs.h"

#include "colmap/mvs/fusion.h"
#include "colmap/sensor/bitmap.h"

#include <filesystem>
#include <iostream>

#include <FreeImage.h>

int main() {
  std::string path =
      "/mnt/common_storage/luchuanchuan/pc_seg/mask2former_output/labels_m2f/1/"
      "A/1A0012.png";
  const FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path.c_str(), 0);
  std::cout << "yes" << std::endl;
  if (format == FIF_UNKNOWN) {
    return 0;
  }
  std::cout << format << std::endl;
  colmap::Bitmap bitmap;
  bitmap.Read(path, 0, 1);
  uint8_t label;
  bitmap.GetSemantic(491, 327, &label);
  std::cout << label - uint8_t(0) << std::endl;

  std::string output_path =
      "/mnt/common_storage/Ganymede/tmp/zhuhai/dense3/fused_rgb.ply";
  std::filesystem::path instance_save_path =
      std::filesystem::path(output_path).parent_path() / "instance.bin";
  std::cout << instance_save_path.string() << std::endl;
  // std::vector<uint8_t> a{0, 1, 1, 4, 7, 9};
  // auto res = colmap::mvs::internal::GetHighestPriority(a);
  // auto color = colmap::mvs::label2color[res];
  // std::cout << int(std::get<0>(color)) << " " << int(std::get<1>(color)) << "
  // " << int(std::get<2>(color)) << " " << std::endl; std::cout << res -
  // uint8_t(0) << std::endl;

  // colmap::mvs::Workspace::Options workspace_options;
  // colmap::mvs::StereoFusionOptions options_;

  // std::string workspace_format_lower_case = "colmap";
  // colmap::StringToLower(&workspace_format_lower_case);

  // workspace_options.num_threads = options_.num_threads;;
  // workspace_options.max_image_size = options_.max_image_size;
  // workspace_options.image_as_rgb = true;
  // workspace_options.semantic_path =
  // "/mnt/common_storage/luchuanchuan/pc_seg/mask2former_output/labels_m2f";
  // workspace_options.as_semantic = true;
  // workspace_options.instance_path = "";
  // workspace_options.as_instance = false;
  // workspace_options.cache_size = options_.cache_size;
  // workspace_options.workspace_path =
  // "/mnt/luchuanchuan/project/pc_seg/data/zhuhai1440/images_2000/dense";
  // workspace_options.workspace_format = "COLMAP";
  // workspace_options.input_type = "geometric";

  return 0;
}