#include <string>
#include <platformdirs.h>
#include <fmt/format.h>

int main(int argc, char *argv[]) {
    const std::string app_name = "MyApp";
    const std::string app_author = "MyCompany";

    fmt::println("-- platformdirs {}", platformdirs::version_);

    fmt::println("-- app dirs (with optional 'version')");
    const auto dirs = platformdirs::platform_dirs(app_name, app_author, "1.0");
    fmt::println("user_data_dir: {}", dirs.user_data_dir());
    fmt::println("user_config_dir: {}", dirs.user_config_dir());
    fmt::println("user_cache_dir: {}", dirs.user_cache_dir());
    fmt::println("user_state_dir: {}", dirs.user_state_dir());
    fmt::println("user_log_dir: {}", dirs.user_log_dir());
    fmt::println("user_documents_dir: {}", dirs.user_documents_dir());
    fmt::println("user_downloads_dir: {}", dirs.user_downloads_dir());
    fmt::println("user_pictures_dir: {}", dirs.user_pictures_dir());
    fmt::println("user_videos_dir: {}", dirs.user_videos_dir());
    fmt::println("user_music_dir: {}", dirs.user_music_dir());
    fmt::println("user_runtime_dir: {}", dirs.user_runtime_dir());
    fmt::println("site_data_dir: {}", dirs.site_data_dir());
    fmt::println("site_config_dir: {}", dirs.site_config_dir());
    fmt::println("site_cache_dir: {}", dirs.site_cache_dir());
    fmt::println("site_runtime_dir: {}", dirs.site_runtime_dir());

    fmt::println("-- app dirs (without optional 'version')");
    const auto dirs = platformdirs::platform_dirs(app_name, app_author);
    fmt::println("user_data_dir: {}", dirs.user_data_dir());
    fmt::println("user_config_dir: {}", dirs.user_config_dir());
    fmt::println("user_cache_dir: {}", dirs.user_cache_dir());
    fmt::println("user_state_dir: {}", dirs.user_state_dir());
    fmt::println("user_log_dir: {}", dirs.user_log_dir());
    fmt::println("user_documents_dir: {}", dirs.user_documents_dir());
    fmt::println("user_downloads_dir: {}", dirs.user_downloads_dir());
    fmt::println("user_pictures_dir: {}", dirs.user_pictures_dir());
    fmt::println("user_videos_dir: {}", dirs.user_videos_dir());
    fmt::println("user_music_dir: {}", dirs.user_music_dir());
    fmt::println("user_runtime_dir: {}", dirs.user_runtime_dir());
    fmt::println("site_data_dir: {}", dirs.site_data_dir());
    fmt::println("site_config_dir: {}", dirs.site_config_dir());
    fmt::println("site_cache_dir: {}", dirs.site_cache_dir());
    fmt::println("site_runtime_dir: {}", dirs.site_runtime_dir());

    fmt::println("-- app dirs (without optional 'appauthor')");
    const auto dirs = platformdirs::platform_dirs(app_name);
    fmt::println("user_data_dir: {}", dirs.user_data_dir());
    fmt::println("user_config_dir: {}", dirs.user_config_dir());
    fmt::println("user_cache_dir: {}", dirs.user_cache_dir());
    fmt::println("user_state_dir: {}", dirs.user_state_dir());
    fmt::println("user_log_dir: {}", dirs.user_log_dir());
    fmt::println("user_documents_dir: {}", dirs.user_documents_dir());
    fmt::println("user_downloads_dir: {}", dirs.user_downloads_dir());
    fmt::println("user_pictures_dir: {}", dirs.user_pictures_dir());
    fmt::println("user_videos_dir: {}", dirs.user_videos_dir());
    fmt::println("user_music_dir: {}", dirs.user_music_dir());
    fmt::println("user_runtime_dir: {}", dirs.user_runtime_dir());
    fmt::println("site_data_dir: {}", dirs.site_data_dir());
    fmt::println("site_config_dir: {}", dirs.site_config_dir());
    fmt::println("site_cache_dir: {}", dirs.site_cache_dir());
    fmt::println("site_runtime_dir: {}", dirs.site_runtime_dir());

    fmt::println("-- app dirs (with disabled 'appauthor')");
    const auto dirs = platformdirs::platform_dirs(app_name, false);
    fmt::println("user_data_dir: {}", dirs.user_data_dir());
    fmt::println("user_config_dir: {}", dirs.user_config_dir());
    fmt::println("user_cache_dir: {}", dirs.user_cache_dir());
    fmt::println("user_state_dir: {}", dirs.user_state_dir());
    fmt::println("user_log_dir: {}", dirs.user_log_dir());
    fmt::println("user_documents_dir: {}", dirs.user_documents_dir());
    fmt::println("user_downloads_dir: {}", dirs.user_downloads_dir());
    fmt::println("user_pictures_dir: {}", dirs.user_pictures_dir());
    fmt::println("user_videos_dir: {}", dirs.user_videos_dir());
    fmt::println("user_music_dir: {}", dirs.user_music_dir());
    fmt::println("user_runtime_dir: {}", dirs.user_runtime_dir());
    fmt::println("site_data_dir: {}", dirs.site_data_dir());
    fmt::println("site_config_dir: {}", dirs.site_config_dir());
    fmt::println("site_cache_dir: {}", dirs.site_cache_dir());
    fmt::println("site_runtime_dir: {}", dirs.site_runtime_dir());

    return 0;
}
