/*
 * settings.c
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */

#include "settings.h"

void settings_screen_create(lv_obj_t *parent) {
  lv_obj_t *label = lv_label_create(parent);
  lv_label_set_text(label, "Settings Screen");
  lv_obj_center(label);
}
