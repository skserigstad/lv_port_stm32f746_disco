/*
 * home_screen.c
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */

#include "home_screen.h"
#include "global_styles.h"


void ui_home_create(lv_obj_t *parent) {
  lv_obj_t *label = lv_label_create(parent);
  lv_label_set_text(label, "Home Screen");
  lv_obj_center(label);
}


