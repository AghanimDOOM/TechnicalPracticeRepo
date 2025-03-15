#include "lvgl_ui.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C"{
#endif

extern lv_image_dsc_t mouse_cursor_icon;

#if LV_USE_LINUX_FBDEV
void lv_driver_init(void)
{
    lv_display_t * disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0");
}
#elif LV_USE_LINUX_DRM
void lv_driver_init(void)
{
    lv_display_t * disp = lv_linux_drm_create();
    lv_linux_drm_set_file(disp, "/dev/dri/card0", -1);

    lv_indev_t* mouse = lv_libinput_create(LV_INDEV_TYPE_POINTER, "/dev/input/event3");
    lv_obj_t* mouse_cursor = lv_image_create(lv_scr_act());
    lv_image_set_src(mouse_cursor, &mouse_cursor_icon);
    lv_indev_set_cursor(mouse, mouse_cursor);
    lv_indev_set_display(mouse, disp);
}
#elif LV_USE_SDL
void lv_driver_init(void)
{
    lv_sdl_window_create(800, 480);
}
#else
#error Unsupported configuration
#endif

#ifdef __cplusplus
}
#endif
