#include <format>
#include <print>
#include <platformdirs.h>
#include <string>

int main(int argc, char *argv[]) {
  const std::string app_name = "MyApp";
  const std::string app_author = "MyCompany";

  std::println("-- platformdirs {} --", platformdirs::version_());

  std::println("-- app dirs (with optional 'version')");
  auto dirs = platformdirs::platform_dirs(app_name, app_author, "1.0");
  std::println("user_data_dir: {}", dirs.user_data_dir());
  std::println("user_config_dir: {}", dirs.user_config_dir());
  std::println("user_cache_dir: {}", dirs.user_cache_dir());
  std::println("user_state_dir: {}", dirs.user_state_dir());
  std::println("user_log_dir: {}", dirs.user_log_dir());
  std::println("user_documents_dir: {}", dirs.user_documents_dir());
  std::println("user_downloads_dir: {}", dirs.user_downloads_dir());
  std::println("user_pictures_dir: {}", dirs.user_pictures_dir());
  std::println("user_videos_dir: {}", dirs.user_videos_dir());
  std::println("user_music_dir: {}", dirs.user_music_dir());
  std::println("user_runtime_dir: {}", dirs.user_runtime_dir());
  std::println("site_data_dir: {}", dirs.site_data_dir());
  std::println("site_config_dir: {}", dirs.site_config_dir());
  std::println("site_cache_dir: {}", dirs.site_cache_dir());
  std::println("site_runtime_dir: {}", dirs.site_runtime_dir());

  std::println("");
  std::println("-- app dirs (without optional 'version')");
  dirs = platformdirs::platform_dirs(app_name, app_author);
  std::println("user_data_dir: {}", dirs.user_data_dir());
  std::println("user_config_dir: {}", dirs.user_config_dir());
  std::println("user_cache_dir: {}", dirs.user_cache_dir());
  std::println("user_state_dir: {}", dirs.user_state_dir());
  std::println("user_log_dir: {}", dirs.user_log_dir());
  std::println("user_documents_dir: {}", dirs.user_documents_dir());
  std::println("user_downloads_dir: {}", dirs.user_downloads_dir());
  std::println("user_pictures_dir: {}", dirs.user_pictures_dir());
  std::println("user_videos_dir: {}", dirs.user_videos_dir());
  std::println("user_music_dir: {}", dirs.user_music_dir());
  std::println("user_runtime_dir: {}", dirs.user_runtime_dir());
  std::println("site_data_dir: {}", dirs.site_data_dir());
  std::println("site_config_dir: {}", dirs.site_config_dir());
  std::println("site_cache_dir: {}", dirs.site_cache_dir());
  std::println("site_runtime_dir: {}", dirs.site_runtime_dir());

  std::println("");
  std::println("-- app dirs (without optional 'appauthor')");
  dirs = platformdirs::platform_dirs(app_name);
  std::println("user_data_dir: {}", dirs.user_data_dir());
  std::println("user_config_dir: {}", dirs.user_config_dir());
  std::println("user_cache_dir: {}", dirs.user_cache_dir());
  std::println("user_state_dir: {}", dirs.user_state_dir());
  std::println("user_log_dir: {}", dirs.user_log_dir());
  std::println("user_documents_dir: {}", dirs.user_documents_dir());
  std::println("user_downloads_dir: {}", dirs.user_downloads_dir());
  std::println("user_pictures_dir: {}", dirs.user_pictures_dir());
  std::println("user_videos_dir: {}", dirs.user_videos_dir());
  std::println("user_music_dir: {}", dirs.user_music_dir());
  std::println("user_runtime_dir: {}", dirs.user_runtime_dir());
  std::println("site_data_dir: {}", dirs.site_data_dir());
  std::println("site_config_dir: {}", dirs.site_config_dir());
  std::println("site_cache_dir: {}", dirs.site_cache_dir());
  std::println("site_runtime_dir: {}", dirs.site_runtime_dir());

  std::println("");
  std::println("-- app dirs (with disabled 'appauthor')");
  dirs = platformdirs::platform_dirs(app_name, false);
  std::println("user_data_dir: {}", dirs.user_data_dir());
  std::println("user_config_dir: {}", dirs.user_config_dir());
  std::println("user_cache_dir: {}", dirs.user_cache_dir());
  std::println("user_state_dir: {}", dirs.user_state_dir());
  std::println("user_log_dir: {}", dirs.user_log_dir());
  std::println("user_documents_dir: {}", dirs.user_documents_dir());
  std::println("user_downloads_dir: {}", dirs.user_downloads_dir());
  std::println("user_pictures_dir: {}", dirs.user_pictures_dir());
  std::println("user_videos_dir: {}", dirs.user_videos_dir());
  std::println("user_music_dir: {}", dirs.user_music_dir());
  std::println("user_runtime_dir: {}", dirs.user_runtime_dir());
  std::println("site_data_dir: {}", dirs.site_data_dir());
  std::println("site_config_dir: {}", dirs.site_config_dir());
  std::println("site_cache_dir: {}", dirs.site_cache_dir());
  std::println("site_runtime_dir: {}", dirs.site_runtime_dir());

  return 0;
}
