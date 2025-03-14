#include "lvgl_ui.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C"{
#endif

#if LV_USE_LINUX_FBDEV
void lv_linux_disp_init(void)
{
    lv_display_t * disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0");
}
#elif LV_USE_LINUX_DRM
void lv_linux_disp_init(void)
{
    lv_display_t * disp = lv_linux_drm_create();
    lv_linux_drm_set_file(disp, "/dev/dri/card0", -1);
}
#elif LV_USE_SDL
void lv_linux_disp_init(void)
{
    lv_sdl_window_create(800, 480);
}
#else
#error Unsupported configuration
#endif

#ifdef __cplusplus
}
#endif
