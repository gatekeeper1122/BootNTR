#ifndef DRAW_H
#define DRAW_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <3ds.h>
#include <citro3d.h>
#include "vshader_shbin.h"

#define CLEAR_COLOR			0x68B0D8FF
#define SCREEN_POS(x, y)	(screenPos_t)((x << 16) | (y))
#define POS_X(screenPos)	(float)(screenPos >> 16)
#define POS_Y(screenPos)	(float)(screenPos & 0xFFFF)

#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
	GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

typedef struct
{
	float	position[3];
	float	texcoord[2];
}			textVertex_s;
typedef struct
{
	float	posX;
	float	posY;
}			cursor_t;

enum drawFlags
{
	BOLD = BIT(0),
	SKINNY = BIT(1),
	BIG = BIT(2),
	SMALL = BIT(4),
	NEWLINE = BIT(5)
};

typedef u32 screenPos_t;

void drawText(screenPos_t pos, float size, u32 color, char *text, ...);
void drawInit(void);
void drawExit(void);
void updateScreen(void);
void setScreen(gfxScreen_t screen);
void Printf(u32 color, u32 flags, char *text, ...);

#define COLOR_BLUE	0xFFFF0000
#define COLOR_RED	0xFF0000FF
#define COLOR_GREEN	0xFF00FF00
#define COLOR_BLANK	0xFFFFFFFF
#define COLOR_BLACK	0xFF000000
#define COLOR_GREY	0xFF989898
#define COLOR_ORANGE 0xFF00A5FF

#define COLOR_DARKGREEN	0xFF006400



#endif