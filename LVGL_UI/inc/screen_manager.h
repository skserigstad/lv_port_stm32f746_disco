/*
 * screen_manager.h
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */

#ifndef LVGL_UI_INC_SCREEN_MANAGER_H_
#define LVGL_UI_INC_SCREEN_MANAGER_H_

#include "lvgl/lvgl.h"

typedef enum {
  SCREEN_HOME,
  SCREEN_SETTINGS,
  SCREEN_LOGS,
} screen_id_t;

void screen_manager_init(lv_obj_t *parent);
void screen_manager_set_active(screen_id_t screen_id);
screen_id_t screen_manager_get_active();

#endif /* LVGL_UI_INC_SCREEN_MANAGER_H_ */
