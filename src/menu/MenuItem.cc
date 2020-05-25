#include "MenuItem.h"
#include "Menu2D.h"

#include <png/png.h>

MenuItem::MenuItem(const FontRenderer &font_renderer, const Perso *perso, const char *texture_path, pvr_ptr_t background)
    : font_renderer_(font_renderer),
      perso_(perso),
      background_(background)
{
    character_texture_ = pvr_mem_malloc(256 * 256 * 2);
    png_to_texture(texture_path, character_texture_, PNG_FULL_ALPHA);
}

void MenuItem::RenderDetails(int filter_mode) const
{
    char temp[10];

    pvr_wait_ready();
    pvr_scene_begin();

    pvr_list_begin(PVR_LIST_OP_POLY);

    pvr_list_finish();

    pvr_list_begin(PVR_LIST_TR_POLY);
    Menu2D::draw_alp_tex_box(0.0, 0.0, 1024.0, 1024.0, 0.1, 1024, background_, 1.0);
    Menu2D::draw_poly_box(30.0f, 30.0f, 610.0f, 450.0f, 0.1f, 0.5f, 1.0f, 0.0f, 0.5f, 0.5f, 0.8f, 0.8f, 0.8f);
    font_renderer_.WriteWord("Name", filter_mode, 25, 150, 256, 0.0, 0.0, 0.0);
    font_renderer_.WriteWord("Age:", filter_mode, 25, 150, 286, 0.0, 0.0, 0.0);
    font_renderer_.WriteWord("Country:", filter_mode, 25, 150, 316, 0.0, 0.0, 0.0);
    font_renderer_.WriteWord("Vehicule:", filter_mode, 25, 150, 346, 0.0, 0.0, 0.0);


    sprintf(temp, "%d", perso_->age());
    Menu2D::draw_alp_tex_box(0.0, 0.0, 256.0, 256.0, 1.0, 256, character_texture_, 1.0);
    font_renderer_.WriteWord(perso_->name(), filter_mode, 25, 320, 256, 0.0, 0.0, 0.0);
    font_renderer_.WriteWord(temp, filter_mode, 25, 320, 286, 0.0, 0.0, 0.0);
    font_renderer_.WriteWord(perso_->country(), filter_mode, 25, 320, 316, 0.0, 0.0, 0.0);
    font_renderer_.WriteWord(perso_->vehicle(), filter_mode, 25, 320, 346, 0.0, 0.0, 0.0);

    pvr_list_finish();
    pvr_scene_finish();
}