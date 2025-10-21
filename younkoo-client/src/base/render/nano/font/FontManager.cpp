#include "../NanovgHelper.hpp"
#include "../../resources/fonts/harmony_sc_regular.h"
#include "../../resources/fonts/harmony_sc_bold.h"

#include "../../resources/fonts/GreycliffCF_Light.h"
#include "../../resources/fonts/material_icon.h"

void NanoVGHelper::LoadFonts() {
	fontHarmony = nvgCreateFontMem(Context, "harmony_sans_regular", harmony_sc_regular, harmony_sc_regular_size, 0);
	fontHarmonyBold = nvgCreateFontMem(Context, "harmony_sans_bold", harmony_sc_bold, harmony_sc_bold_size, 0);
	fontGreycliffCFLight = nvgCreateFontMem(Context, "GreycliffCF-Light", GreycliffCFLight, GreycliffCFLight_size, 0);
	fontMaterialIcon = nvgCreateFontMem(Context, "material-icon", material_icon, material_icon_size, 0);
}