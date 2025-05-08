/*
 * global_styles.h
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */

#ifndef LVGL_UI_INC_GLOBAL_STYLES_H_
#define LVGL_UI_INC_GLOBAL_STYLES_H_

#include "lvgl/lvgl.h"

void global_styles_init(void);

extern lv_style_t global_style;
extern lv_style_t main_screen_style;

extern lv_style_t button_icon_style;
extern lv_style_t button_style;

extern lv_style_t icon_active_style;
extern lv_style_t icon_inactive_style;

#endif /* LVGL_UI_INC_GLOBAL_STYLES_H_ */
