/*
 * status_bar.c
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */

#include "status_bar.h"
#include "color_palette.h"
#include "global_styles.h"
#include "screen_manager.h"

static lv_obj_t *status_bar;
static lv_obj_t *running_icon;
static lv_obj_t *iso_icons[3];
static lv_obj_t *pause_btn;
static lv_obj_t *settings_btn;
static lv_obj_t *settings_btn_icon;
static bool is_settings_screen_active = false;

// Local styles
static lv_style_t left_container_style;
static lv_style_t right_container_style;
static lv_style_t status_bar_style;

// Global variables
bool is_paused = false;

// Define symbol labels
#define PUMP_RUNNING LV_SYMBOL_REFRESH
#define ISO_PTO LV_SYMBOL_SHUFFLE
#define ISO_PICKUP LV_SYMBOL_UP
#define ISO_SPEED LV_SYMBOL_LEFT

// Function to initialize styles
static void init_styles() {
  // Status bar style
  lv_style_init(&status_bar_style);
  lv_style_set_radius(&status_bar_style, 0);
  lv_style_set_size(&status_bar_style, lv_pct(100), lv_pct(15));
  lv_style_set_bg_color(&status_bar_style, BRAND_GREY);
  lv_style_set_pad_all(&status_bar_style, 0);
  lv_style_set_margin_top(&status_bar_style, 0);
  lv_style_set_margin_bottom(&status_bar_style, 0);
  lv_style_set_margin_right(&status_bar_style, 0);
  lv_style_set_margin_left(&status_bar_style, 0);

  // Left container style
  lv_style_init(&left_container_style);
  lv_style_set_bg_color(&left_container_style, BRAND_DARK_GREEN);
  lv_style_set_radius(&left_container_style, 0);
  lv_style_set_pad_all(&left_container_style, 0);
  lv_style_set_pad_left(&left_container_style, 10);
  lv_style_set_height(&left_container_style, lv_pct(100));
  lv_style_set_flex_grow(&left_container_style, 4);
  lv_style_set_flex_flow(&left_container_style, LV_FLEX_FLOW_ROW);
  lv_style_set_pad_row(&left_container_style, 15);

  // Right container style
  lv_style_init(&right_container_style);
  lv_style_set_bg_color(&right_container_style, BRAND_GREY);
  lv_style_set_radius(&right_container_style, 0);
  lv_style_set_pad_all(&right_container_style, 0);
  lv_style_set_border_width(&right_container_style, 0);
  lv_style_set_height(&right_container_style, lv_pct(100));
  lv_style_set_flex_grow(&right_container_style, 1);
  lv_style_set_flex_flow(&right_container_style, LV_FLEX_FLOW_ROW);
  lv_style_set_pad_row(&right_container_style, 15);
}

// Function to handle settings button click
static void settings_btn_event_handler(lv_event_t *e) {
  if (is_settings_screen_active) {
    // switch back to home screen
    screen_manager_set_active(SCREEN_HOME);
    lv_label_set_text(settings_btn_icon, LV_SYMBOL_SETTINGS);
    is_settings_screen_active = false;
  } else {
    // switch to settings screen
    screen_manager_set_active(SCREEN_SETTINGS);
    lv_label_set_text(settings_btn_icon, LV_SYMBOL_HOME);
    is_settings_screen_active = true;
  }
}

// Function to handle pause button click
static void pause_btn_event_handler(lv_event_t *e) {
  // Toggle the pause state
  is_paused = !is_paused;

  // Set the screen to paused
  // TODO: Implement pause screen
  // Add pause screen as overlay

  /*Toggle pause button visibility using:
  Hide:
  lv_obj_add_flag(pause_btn, LV_OBJ_FLAG_HIDDEN);
  Show:
  lv_obj_clear_flag(pause_btn, LV_OBJ_FLAG_HIDDEN);
  */

  // Update system about pause state
}

static void add_running_icon(lv_obj_t *parent) {
  running_icon = lv_label_create(parent);
  lv_label_set_text(running_icon, PUMP_RUNNING);
  lv_obj_add_style(running_icon, &icon_active_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Function to add ISO status icons
static void add_iso_icons(lv_obj_t *parent) {
  const char *iso_symbols[3] = {ISO_PTO, ISO_PICKUP, ISO_SPEED};
  for (int i = 0; i < 3; i++) {
    iso_icons[i] = lv_label_create(parent);
    lv_label_set_text(iso_icons[i], iso_symbols[i]);
    lv_obj_add_style(iso_icons[i], &icon_inactive_style,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
  }
}

// Function to add the pause button
static void add_pause_button(lv_obj_t *parent) {
  pause_btn = lv_btn_create(parent);
  lv_obj_add_style(pause_btn, &button_style, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_event_cb(pause_btn, pause_btn_event_handler, LV_EVENT_CLICKED,
                      NULL);

  lv_obj_t *pause_icon = lv_label_create(pause_btn);
  lv_label_set_text(pause_icon, LV_SYMBOL_PAUSE);
  lv_obj_add_style(pause_icon, &button_icon_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_center(pause_icon);
}

// Function to add the settings button
static void add_settings_button(lv_obj_t *parent) {
  settings_btn = lv_btn_create(parent);
  lv_obj_add_style(settings_btn, &button_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_event_cb(settings_btn, settings_btn_event_handler,
                      LV_EVENT_CLICKED, NULL);

  settings_btn_icon = lv_label_create(settings_btn);
  lv_label_set_text(settings_btn_icon,
                    LV_SYMBOL_SETTINGS); // Default to settings icon
  lv_obj_add_style(settings_btn_icon, &button_icon_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_center(settings_btn_icon);
}

// Function to create the status bar
lv_obj_t *ui_status_bar_create(lv_obj_t *parent) {
  // Initialize styles
  init_styles();

  status_bar = lv_obj_create(parent);
  lv_obj_add_style(status_bar, &status_bar_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_flex_flow(status_bar, LV_FLEX_FLOW_ROW);

  // Create left container for running and ISO icons
  lv_obj_t *left_container = lv_obj_create(status_bar);
  lv_obj_add_style(left_container, &left_container_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_flex_align(left_container, LV_FLEX_ALIGN_START,
                        LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  add_running_icon(left_container);
  add_iso_icons(left_container);

  // Create right container for pause and settings buttons
  lv_obj_t *right_container = lv_obj_create(status_bar);
  lv_obj_add_style(right_container, &right_container_style,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_flex_align(right_container, LV_FLEX_ALIGN_SPACE_AROUND,
                        LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  add_pause_button(right_container);
  add_settings_button(right_container);

  return status_bar;
}
