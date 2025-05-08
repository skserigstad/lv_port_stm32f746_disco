/*
 * screen_manager.c
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */

#include "screen_manager.h"
#include "global_styles.h"
#include "home_screen.h"
#include "settings.h"


static lv_obj_t *main_screen_container;
static screen_id_t active_screen = SCREEN_HOME;

void screen_manager_init(lv_obj_t *parent) {
  // Create main content area
  main_screen_container = lv_obj_create(parent);
  lv_obj_add_style(main_screen_container, &main_screen_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  screen_manager_set_active(SCREEN_HOME);
}

void screen_manager_set_active(screen_id_t screen_id) {
  lv_obj_clean(main_screen_container); // Clear previous screen

  switch (screen_id) {
  case SCREEN_HOME:
    ui_home_create(main_screen_container);
    break;
  case SCREEN_SETTINGS:
    settings_screen_create(main_screen_container);
    break;
  default:
    break;
  }

  active_screen = screen_id;
}

screen_id_t screen_manager_get_active() { return active_screen; }

