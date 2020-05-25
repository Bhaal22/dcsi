#pragma once

#include <memory>

#include <kos.h>

#include "FontRenderer.h"
#include "perso.h"


class MenuItem
{
public:
    MenuItem(const FontRenderer &font_renderer, const Perso *perso, const char *texture_path, pvr_ptr_t background);

    void RenderDetails(int filter_mode) const;

private:
    const FontRenderer &font_renderer_;
    std::unique_ptr<const Perso> perso_;
    pvr_ptr_t character_texture_;
    pvr_ptr_t background_;
};