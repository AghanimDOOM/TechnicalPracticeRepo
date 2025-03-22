#include <pthread.h>
#include <unistd.h>

#include "lvgl_ui.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C"{
#endif

static pthread_t tid;

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
#elif LV_USE_WAYLAND
void lv_driver_init(void)
{
    lv_disp_t* disp = lv_wayland_window_create(800, 480, "desktop", NULL);
    // lv_indev_t* mouse = lv_wayland_get_pointer(disp);
    // lv_obj_t* mouse_cursor = lv_image_create(lv_scr_act());
    // lv_image_set_src(mouse_cursor, &mouse_cursor_icon);
    // lv_indev_set_cursor(mouse, mouse_cursor);
    // lv_indev_set_display(mouse, disp);
}
#else
#error Unsupported configuration
#endif


void* lvgl_thread(void* arg)
{
    while(1){
        // lv_wayland_timer_handler();
        lv_timer_handler();
        usleep(5000);
    }
}

void lvgl_init()
{
    // lvgl init
    lv_init();

    // lvgl dirver init
    lv_driver_init();

    // 创建事件处理线程
    pthread_create(&tid,NULL,lvgl_thread,NULL);
}

#ifdef __cplusplus
}
#endif
