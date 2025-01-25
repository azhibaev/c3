Create headers in include directory :

	for /R %i in (*.mod.h) do mod_to_h %i include


Make mod_to_h.exe :

	dmc -Iinclude -Icommon -Imodule -Ichars -Iparse -Iutopia mod_to_h\mod_to_h.c

