#pragma once

#include <memory>

#include <dcplib/fnt.h>

class FontRenderer
{
public:
    FontRenderer(const char *font_path);
    ~FontRenderer();

    void WriteWord(const char *word, int filter_mode, int size, int posx, int posy, float r, float g, float b) const;

private:
    std::unique_ptr<fntRenderer> font_renderer_;
};