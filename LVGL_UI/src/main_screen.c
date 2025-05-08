/*
 * main_screen.c
 *
 *  Created on: May 8, 2025
 *      Author: SolveigKorslien
 */

#include "main_screen.h"
#include "global_styles.h"
#include "color_palette.h"
#include "status_bar.h"
#include "screen_manager.h"


void start_main_screen(void){
	lv_obj_t *scr = lv_scr_act();

	// Create container for the entire screen
	lv_obj_t *main_cont = lv_obj_create(scr);
	  lv_obj_add_style(main_cont, &global_style, LV_PART_MAIN | LV_STATE_DEFAULT);
	  lv_obj_set_size(main_cont, lv_pct(100), lv_pct(100));
	  lv_obj_set_style_bg_color(main_cont, lv_color_hex(0xB6EAB1), 0);
	  lv_obj_set_style_pad_all(main_cont, 0, 0);
	  lv_obj_set_flex_flow(main_cont, LV_FLEX_FLOW_COLUMN);
	  lv_obj_set_style_pad_row(main_cont, 0, 0);

	    global_styles_init();

	    // Create status bar
	    ui_status_bar_create(main_cont);

	    // Create main content area
	    screen_manager_init(main_cont);

}
