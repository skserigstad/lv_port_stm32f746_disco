/*
 * global_styles.c
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */


#include "global_styles.h"
#include "color_palette.h"

lv_style_t global_style;

lv_style_t main_screen_style;

lv_style_t status_bar_style;

lv_style_t button_icon_style;
lv_style_t button_style;

lv_style_t icon_active_style;
lv_style_t icon_inactive_style;

void global_styles_init(void) {
  lv_style_init(&global_style);
  lv_style_set_radius(&global_style, 0);

  // Main screen style
  lv_style_init(&main_screen_style);
  lv_style_set_radius(&main_screen_style, 0);
  lv_style_set_size(&main_screen_style, lv_pct(100), lv_pct(85));

  // Button style
  lv_style_init(&button_style);
  lv_style_set_size(&button_style, lv_pct(35), lv_pct(90));
  lv_style_set_bg_color(&button_style, BRAND_DARK_GREEN);
  lv_style_set_radius(&button_style, 5);
  lv_style_set_margin_top(&button_style, 0);
  lv_style_set_margin_bottom(&button_style, 0);
  lv_style_set_margin_left(&button_style, 0);
  lv_style_set_margin_right(&button_style, 0);

  // Button icon style
  lv_style_init(&button_icon_style);
  lv_style_set_text_font(&button_icon_style, &lv_font_montserrat_28);
  lv_style_set_text_color(&button_icon_style, WHITE);

  // Active icon style
  lv_style_init(&icon_active_style);
  lv_style_set_text_font(&icon_active_style, &lv_font_montserrat_26);
  lv_style_set_text_color(&icon_active_style, BRAND_YELLOW);

  // Inactive icon style
  lv_style_init(&icon_inactive_style);
  lv_style_set_text_font(&icon_inactive_style, &lv_font_montserrat_26);
  lv_style_set_text_color(&icon_inactive_style, BRAND_GREY);
}
