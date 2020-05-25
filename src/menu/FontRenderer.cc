#include "FontRenderer.h"

FontRenderer::FontRenderer(const char *font_path)
    : font_renderer_(new fntRenderer())
{
    auto text_fonts = new fntTexFont("/rd/sorority.txf");

    font_renderer_->setFont(text_fonts);
}

FontRenderer::~FontRenderer() { }


void FontRenderer::WriteWord(const char *word, int filter_mode, int size, int posx, int posy, float r, float g, float b) const
{
    font_renderer_->setFilterMode(filter_mode);

    font_renderer_->setPointSize(size);

    font_renderer_->begin();
    font_renderer_->setColor(r, g, b);
    font_renderer_->start2f(posx, posy);
    font_renderer_->puts(word);
    font_renderer_->end();
}